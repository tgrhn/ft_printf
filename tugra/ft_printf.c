/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:28:19 by tkarakad          #+#    #+#             */
/*   Updated: 2023/07/19 14:45:43 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_control(va_list args, char c)
{
	int	p_length;

	p_length = 0;
	if (c == 'c')
		p_length += ft_putchar(va_arg(args, int));
	if (c == 's')
		p_length += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		p_length += ft_putnbr(va_arg(args, int));
	if (c == '%')
		p_length += ft_putchar('%');
	if (c == 'x')
		p_length += print_lower_hexa(va_arg(args, unsigned int)); 
	if (c == 'X')
		p_length += print_upper_hexa(va_arg(args, unsigned int));
	if (c == 'p')
		p_length = p_length + ft_putchar('0') 
			+ ft_putchar('x') 
			+ print_lower_hexa((unsigned long)va_arg(args, void *));
	if (c == 'u')
		p_length += ft_putnbr(va_arg(args, unsigned int));
	return (p_length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			length += ft_control(args,*s);
		}
		else 
			length += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return ((int)length);
}
