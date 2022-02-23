#include "../ft_printf.h"

int ft_putstr(char *s)
{
	int	printed;

	printed = 0;
	while (s && *s != '\0')
		printed += ft_putchar(*s++);
	return (0);
}