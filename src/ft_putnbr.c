#include "../ft_printf.h"

int ft_putnbr(int num)
{
	int	printed;
	int	last;

	printed = 0;
	if (num <= -10)
		printed += ft_putnbr (num / -10);
	if (num >= 10)
		printed += ft_putnbr (num / 10);
	last = num % 10;
	if (last < 0)
		last *= -1;
	ft_putchar('0' + last);
	printed++;	
	return (printed);
}