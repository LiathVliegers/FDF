/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_liath.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liath <liath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:21:00 by livliege          #+#    #+#             */
/*   Updated: 2024/05/20 16:31:12 by liath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIATH_H
# define LIB_LIATH_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>

# define FD_LIMIT 1024

# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[33m"
# define BLUE "\033[94m"
# define PURPLE "\033[35m"
# define LIGHTBLUE "\033[36m"
# define DEFAULT "\033[0m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// libft:
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);

void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_wordcount(char const *s, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

// get_next_line:
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	*ft_memset_gnl(void *s, int c, size_t n);

char	*ft_get_remainder(char *line_nlc_remainder);
char	*ft_get_line(char *line_nlc_remainder);
char	*ft_read(int fd, char *line_nlc_remainder);
char	*get_next_line(int fd);

// ft_printf:
int		ft_format_specefier(char placeholder, va_list arguments);
int		ft_printf(const char *string_to_print, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
void	ft_print_hexadecimal(unsigned long num, char placeholder);
int		ft_hexadecimal(unsigned long h, char placeholder);
int		ft_print_pointer_address(unsigned long p, char placeholder);
int		ft_print_number(int d);
int		ft_print_unsigned_number(unsigned int u);
char	*itoa_converter_pf(int n, char *str, size_t n_len);
char	*ft_itoa_pf(int n, char *str);
char	*uitoa_converter(unsigned int n, char *str, size_t n_len);
char	*ft_uitoa(unsigned int n, char *str);

#endif
