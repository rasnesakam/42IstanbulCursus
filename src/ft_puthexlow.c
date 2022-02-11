#include "../ft_printf.h"

int ft_puthexlow(unsigned int num)
{
	int printed;

	printed = 0;
	if (num >= 16)
		printed += ft_puthexlow (num / 16);
	ft_putchar ("0123456789abcdef"[num % 16]);
	printed++;
	return (printed);
}