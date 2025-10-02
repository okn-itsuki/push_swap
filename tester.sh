#!/usr/bin/env bash
# ------------------------------------------------------------
# 42 push_swap Tester (Linux)
#   - Randomized and edge-case tests
#   - Verifies with checker_linux (42's official checker)
#   - Counts operations, measures time, Valgrind leak check (always enabled)
#   - Prints per-test result and per-size summary table
# ------------------------------------------------------------
# Usage:
#   chmod +x push_swap_tester.sh
#   ./push_swap_tester.sh [-e ./push_swap] [-c ./checker_linux] \
#                         [--sizes 100,500] [--tests 100,100] \
#                         [--range -1000..1000] [--timeout 5]
# Examples:
#   ./push_swap_tester.sh
#   ./push_swap_tester.sh -e ../push_swap -c ../checker_linux
# ------------------------------------------------------------

set -o pipefail

# --- Defaults ------------------------------------------------
PUSH_SWAP="./push_swap"
CHECKER="./checker"
SIZES=(100 500)
TESTS=(100 100)              # tests per respective size
RAND_RANGE_MIN=-1000
RAND_RANGE_MAX=1000
TIMEOUT_SECS=5

# --- Colors --------------------------------------------------
if [[ -t 1 ]]; then
  RED="\033[31m"; GREEN="\033[32m"; YELLOW="\033[33m"; BLUE="\033[34m"; CYAN="\033[36m"; BOLD="\033[1m"; RESET="\033[0m"
else
  RED=""; GREEN=""; YELLOW=""; BLUE=""; CYAN=""; BOLD=""; RESET=""
fi

# --- Helpers -------------------------------------------------
usage() {
  sed -n '1,40p' "$0"
}

die() { echo -e "${RED}Error:${RESET} $*" >&2; exit 1; }

have() { command -v "$1" >/dev/null 2>&1; }

check_deps() {
  [[ -x "$PUSH_SWAP" ]] || die "push_swap 実行ファイルが見つかりません: $PUSH_SWAP"
  [[ -x "$CHECKER" ]] || die "checker 実行ファイルが見つかりません: $CHECKER"
  have shuf || die "shuf が必要です (coreutils)。"
  have timeout || die "timeout が必要です (coreutils/Moreutils いずれか)。"
  have awk || die "awk が必要です。"
  have seq || die "seq が必要です。"
  have valgrind || die "valgrind が必要です。"
}

parse_sizes() {
  IFS=',' read -r -a SIZES <<<"$1"
}

parse_tests() {
  IFS=',' read -r -a TESTS <<<"$1"
}

parse_range() {
  case "$1" in
    *..*) RAND_RANGE_MIN="${1%%..*}"; RAND_RANGE_MAX="${1##*..}" ;;
    *) die "--range は MIN..MAX の形式で指定してください (例: -500..500)" ;;
  esac
}

int_range_random_unique() {
  local n=$1
  local min=$2
  local max=$3
  local total=$((max - min + 1))
  (( total >= n )) || die "範囲が狭すぎます: 要素=$n, 範囲=${min}..${max}"
  seq "$min" "$max" | shuf -n "$n" | tr '\n' ' ' | sed 's/ $//'
}

is_ok_numeric() {
  local ops_file=$1; shift
  local args=("$@")
  local res
  res=$(cat "$ops_file" | "$CHECKER" "${args[@]}")
  [[ "$res" == "OK" ]]
}

count_ops() {
  local ops_file=$1
  wc -l < "$ops_file"
}

hr() { printf '%*s\n' "${1:-60}" '' | tr ' ' '-'; }

# --- Args ----------------------------------------------------
while [[ $# -gt 0 ]]; do
  case "$1" in
    -h|--help) usage; exit 0 ;;
    -e|--exec) PUSH_SWAP=$2; shift 2 ;;
    -c|--checker) CHECKER=$2; shift 2 ;;
    --sizes) parse_sizes "$2"; shift 2 ;;
    --tests) parse_tests "$2"; shift 2 ;;
    --range) parse_range "$2"; shift 2 ;;
    --timeout) TIMEOUT_SECS=$2; shift 2 ;;
    --) shift; break ;;
    *) echo "Unknown option: $1"; usage; exit 1 ;;
  esac
done

if (( ${#TESTS[@]} != ${#SIZES[@]} )); then
  while (( ${#TESTS[@]} < ${#SIZES[@]} )); do TESTS+=("${TESTS[-1]}"); done
  while (( ${#TESTS[@]} > ${#SIZES[@]} )); do unset 'TESTS[-1]'; done
fi

check_deps

# --- Edge-case suite ----------------------------------------
run_edge_cases() {
  echo -e "${BOLD}${BLUE}Edge cases${RESET}"
  local ok=0 total=0

  ((total++))
  echo -n "Already sorted: "
  if out=$("$PUSH_SWAP" 1 2 3 4 5); then
    if [[ -z "$out" ]]; then echo -e "${GREEN}OK${RESET}"; ((ok++)); else echo -e "${YELLOW}WARN (not empty)${RESET}"; fi
  else
    echo -e "${RED}CRASH${RESET}"
  fi

  ((total++))
  echo -n "Reverse sorted correctness: "
  ops=$(seq 5 -1 1 | xargs "$PUSH_SWAP" 2>/dev/null)
  if [[ $? -eq 0 ]]; then
    if [[ -n "$ops" ]]; then
      if printf '%s\n' "$ops" | "$CHECKER" 5 4 3 2 1 | grep -qx OK; then
        echo -e "${GREEN}OK${RESET}"
        ((ok++))
      else
        echo -e "${RED}KO${RESET}"
      fi
    else
      echo -e "${RED}No ops${RESET}"
    fi
  else
    echo -e "${RED}CRASH${RESET}"
  fi

  declare -a invalid=("1 2 2" "1 a 3" "2147483648" "-2147483649")
  for s in "${invalid[@]}"; do
    ((total++))
    echo -n "Invalid input (${s}): "
    if "$PUSH_SWAP" $s >/dev/null 2>&1; then
      echo -e "${YELLOW}Expected error but exit 0${RESET}"
    else
      echo -e "${GREEN}Error handled${RESET}"
      ((ok++))
    fi
  done
  echo "Edge cases: $ok/$total passed"
  hr
}

# --- Main randomized tests ---------------------------------
declare -A SUM OPS_MIN OPS_MAX OKS TOTALS TIMES

run_random_suite() {
  local size=$1 tests=$2
  local t=1
  SUM[$size]=0; OPS_MIN[$size]=99999999; OPS_MAX[$size]=0; OKS[$size]=0; TOTALS[$size]=$tests; TIMES[$size]=0

  echo -e "${BOLD}${CYAN}Size $size (${tests} tests)${RESET}"
  printf "%5s  %-5s  %-6s  %-10s\n" "#" "OK?" "moves" "time(s)"
  hr 60

  while (( t <= tests )); do
    args=( $(int_range_random_unique "$size" "$RAND_RANGE_MIN" "$RAND_RANGE_MAX") )

    ops_file=$(mktemp)
    start_ns=$(date +%s%N)
    if ! timeout "$TIMEOUT_SECS" "$PUSH_SWAP" "${args[@]}" >"$ops_file" 2>/dev/null; then
      echo -e "$(printf "%5d" "$t")  ${RED}TIMEOUT/CRASH${RESET}"; rm -f "$ops_file"; ((t++)); continue
    fi
    end_ns=$(date +%s%N)
    dt=$(awk -v s="$start_ns" -v e="$end_ns" 'BEGIN{print (e-s)/1000000000}')

    moves=$(count_ops "$ops_file")
    if is_ok_numeric "$ops_file" "${args[@]}"; then
      ok_mark="${GREEN}OK${RESET}"; (( OKS[$size]++ ))
    else
      ok_mark="${RED}KO${RESET}"
    fi

    (( moves < OPS_MIN[$size] )) && OPS_MIN[$size]=$moves
    (( moves > OPS_MAX[$size] )) && OPS_MAX[$size]=$moves
    SUM[$size]=$(( SUM[$size] + moves ))
    TIMES[$size]=$(awk -v a="${TIMES[$size]}" -v b="$dt" 'BEGIN{print a+b}')

    printf "%5d  %-5b  %6d  %10.4f\n" "$t" "$ok_mark" "$moves" "$dt"

    echo -n "    Valgrind: "
    valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42 "$PUSH_SWAP" "${args[@]}" >/dev/null 2>vg.log
    if [[ $? -eq 0 ]]; then
      echo -e "${GREEN}no leaks${RESET}"
    else
      echo -e "${RED}LEAKS/ERRORS (see vg.log)${RESET}"
    fi

    rm -f "$ops_file"
    ((t++))
  done
}

print_summary() {
  hr
  echo -e "${BOLD}${BLUE}Summary${RESET}"
  printf "%-8s %6s %8s %8s %10s %10s %8s\n" "size" "tests" "passed" "rate%" "avg_moves" "time(s)" "best/worst"
  hr
  for ((i=0; i<${#SIZES[@]}; i++)); do
    size=${SIZES[$i]}
    tests=${TOTALS[$size]:-0}
    passed=${OKS[$size]:-0}
    rate=0
    if (( tests > 0 )); then
      rate=$(awk -v p="$passed" -v t="$tests" 'BEGIN{printf "%.1f", (p*100.0)/t}')
    fi
    avg=0
    if (( tests > 0 )); then
      avg=$(awk -v s="${SUM[$size]}" -v t="$tests" 'BEGIN{printf "%.1f", s/t}')
    fi
    total_time=${TIMES[$size]:-0}
    printf "%-8d %6d %8d %8s %10s %10.3f %4d/%-4d\n" \
      "$size" "$tests" "$passed" "$rate" "$avg" "$total_time" "${OPS_MIN[$size]:-0}" "${OPS_MAX[$size]:-0}"
  done
}

# --- Run -----------------------------------------------------
run_edge_cases
for ((i=0; i<${#SIZES[@]}; i++)); do
  run_random_suite "${SIZES[$i]}" "${TESTS[$i]}"
  hr
done
print_summary

exit 0
