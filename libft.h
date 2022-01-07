#ifndef LIBFT_H
#define LIBFT_H

int	ft_atoi(const char *s);
void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(size_t count, size_t size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int ft_isprint(int c);
void 	*ft_memchr(const coid *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, void *src, unsigned int n);

#endif
