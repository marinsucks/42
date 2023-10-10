#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef SIZE_T_DEFINED
#  define SIZE_T_DEFINED
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// memcmp
// memcpy
// memccpy
// memchr
// memcmp
// memset
// memmove
char	*ft_strcat(char *restrict dest, const char *restrict src);
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
// strlcat
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif