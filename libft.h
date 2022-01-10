/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:39:03 by emakas            #+#    #+#             */
/*   Updated: 2022/01/10 19:26:12 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *s);
void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const coid *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, void *src, unsigned int n);
void	*ft_memmove(void *dst, void *src, size_t len);
void	*ft_memset(void *b, int c, unsigned int len);
void	*ft_strchr(const char *s, int c);
void	*ft_strdup(const char *s);
void	*ft_strlcat(const char *s1, const char *s2, size_t dstsize);
void	*ft_strlcpy(char *dest, char *src, unsigned int len);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char c, int fd);
void	ft_putnbr_fd(int num, int fd);
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
