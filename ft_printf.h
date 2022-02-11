/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:06:16 by emakas            #+#    #+#             */
/*   Updated: 2022/02/11 04:33:22 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_print_format(char format, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int num);
int	ft_putptr(unsigned long long addr);
int	ft_putudecimal(unsigned int unum);
int ft_puthexlow(unsigned int num);
int ft_puthexup(unsigned int num);

#endif