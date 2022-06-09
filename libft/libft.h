/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:51:15 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/11/13 17:57:27 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *buf, int val, size_t count);
size_t			ft_strlen(const char *c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *str, int s);
int				ft_strncmp(const char *s1, const char *s2, size_t num);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_atoi(const char *stroka);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int z);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
