/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:42:24 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/08 19:12:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FD_MAX
#  define FD_MAX 512
# endif

# define TRUE 1
# define FALSE 0

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

typedef struct s_gnl_fd_data
{
	int				fd;
	char			stash[BUFFER_SIZE + 1];
}					t_gnl_fd_data;

int			error(int fd);

int			ft_atoi(const char *str);
long		ft_atol(const char *str);
//ft_atoi.c

char		*ft_intbase(unsigned int nbr, char *base, unsigned int baselen);
char		*ft_longbase(unsigned long nbr, char *base, unsigned int baselen);
//ft_base.c

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

void		ft_freetab(char **tab, int heap);
int			ft_free(int mode, ...);
//ft_free.c

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
//ft_is.c

char		*ft_itoa(int n);

size_t		ft_strlen(const char *s);
size_t		ft_tablen(const char **tab);
short int	ft_numlen(long long num);
short int	ft_numlen_base(unsigned long num, unsigned int baselen);
//ft_len.c

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
//ft_lst1.c

void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
int			ft_lstindex(t_list **lst, t_list *tofind);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//ft_lst2.c

void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
//ft_mem.c

void		print_tab(char **tab, int color);
//ft_print.c

int			ft_printf(const char *s, ...);
void		pf_backslash(const char *s, int *count);
int			pf_convert(const char *s, va_list args);
//ft_printf.c

short int	pf_convert_int(va_list args);
int			pf_convert_str(const char *s, va_list args);
short int	pf_convert_ui(const char *s, va_list args);
short int	pf_convert_hex(const char *s, va_list args, char c);
short int	pf_convert_ptr(const char *s, va_list args);
//ft_printf2.c

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putlong_fd(long long n, int fd);
//ft_put.c

void		ft_revert_tab(char *s);
void		ft_revert_inttab(char *s);
//ft_revert.c

char		**ft_split(char const *s, char c);
char		**ft_split_charset(char const *s, char *charset);
//ft_split.c

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
//ft_strcat.c

char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
//ft_strchr.c

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
//ft_strcmp.c

char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
//ft_strcpy.c

char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *src, size_t size);
char		**ft_tabdup(char **tab);
//ft_strdup.c

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_strjoin(char *s1, char *s2, int free_s1, int free_s2);
char		**ft_tabjoin(char **tab, char *str, int free_tab, int free_str);
//ft_strjoin.c

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
//ft_strstr.c

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
//ft_to.c

size_t		ft_wordcount(const char *str, char sep);
size_t		ft_wordcount_cset(const char *str, char *charset);
//ft_wordcount.c

char		*get_next_line(int fd);

char		**get_file(int fd);

void		ft_dfs(char **map, int i, int j, char *notwalls);

#endif
