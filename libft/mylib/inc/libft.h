/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:16:46 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/29 04:59:29 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

// ────────────────────────────────
//         Character checks
// ────────────────────────────────
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

// ────────────────────────────────
//          String functions
// ────────────────────────────────
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(char *str, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_find_next_line(const char *s);

// ────────────────────────────────
//         Memory functions
// ────────────────────────────────
typedef struct s_meta_info
{
	size_t			size;
}					t_meta_info;

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_realloc(void *ptr, size_t size);
void				ft_meta_free(void *ptr);

// ────────────────────────────────
//         Conversion functions
// ────────────────────────────────
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
double				ft_atof(const char *s);
long				ft_labs(long n);
int					ft_abs(int n);

// ────────────────────────────────
//          Output functions
// ────────────────────────────────
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// ────────────────────────────────
//         Split & string tools
// ────────────────────────────────
char				**ft_split(char const *s, char c);
size_t				ft_wordcount(const char *s, char c);
size_t				ft_splitlen(char **split);
void				ft_free_split(char **split);
void				ft_print_split(char **split);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strndup(const char *s, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strendswith(const char *s, const char *suffix);

// ────────────────────────────────
//          get_next_line
// ────────────────────────────────
char				*get_next_line(int fd);

// ────────────────────────────────
//          Linked list
// ────────────────────────────────
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
