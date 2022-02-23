
#include "../ft_printf.h"

int ft_putudecimal(unsigned int num)
{
	int	printed;

	printed = 0;
	if (num >= 10)
		printed += ft_putudecimal(num / 10);
	printed += ft_putchar('0' + (num % 10));
	return (printed);
}