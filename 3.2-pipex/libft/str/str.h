/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:48:31 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/20 19:44:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "../libft.h"

int			ft_atoi(const char *str);

char		*is_valid_base(char *str);
char		*ft_intbase(unsigned int nbr, char *base, unsigned int baselen);
char		*ft_longbase(unsigned long nbr, char *base, unsigned int baselen);
//ft_base.c

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
//ft_is.c

int			ft_is(int c, char *charset);
//ft_is2.c

char		*ft_itoa(int n);

size_t		ft_strlen(const char *s);
size_t		ft_tablen(const char **tab);
short int	ft_numlen(long long num);
short int	ft_numlen_base(unsigned long num, unsigned int baselen);
//ft_len.c

void		ft_revert_tab(char *s);
void		ft_revert_inttab(char *s);
//ft_revert.c

char		**ft_split(char const *s, char c);
char		**ft_split_charset(char const *s, char *charset);
//ft_split.c

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
//ft_strcat

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

int			ft_strset(char *s, char *set);

char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
//ft_strstr.c

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
//ft_tolower.c

size_t		ft_wordcount(const char *str, char sep);
size_t		ft_wordcount_cset(const char *str, char *charset);
//ft_wordcount.c

#endif
