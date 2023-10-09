#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>

#ifndef SIZE_T_DEFINED
typedef unsigned long size_t;
#define SIZE_T_DEFINED
#endif

// atoi
// bzero
// isalnum
// isalpha
// isascii
// isdigit
// isprint
// memcmp
// memcpy
// memccpy
// memchr
// memcmp
// memset
// memmove
// strchr
// strcasecmp
char	*ft_strcat(char *restrict dest, const char *restrict src);
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
// strlcat
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// strncasecmp
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
// strlcpy
// strdup
int		ft_strlen(const char *s);
char	*ft_strrchr(const char *str, int c);
// strspn
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
// tolower
// toupper

#endif