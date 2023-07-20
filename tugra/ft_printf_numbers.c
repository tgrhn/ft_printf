/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:07:11 by tkarakad          #+#    #+#             */
/*   Updated: 2023/07/19 13:23:11 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_putnbr(long c)
{
	int	length;

	length = ft_find_length(c);
	if (c < 10)
		ft_putchar(c + '0');
	else 
	{
		ft_print_putnbr(c / 10);
		ft_print_putnbr(c % 10);
	}
	return (length);
}

int	ft_putnbr(long nb)
{
	int	d_length;

	d_length = 0;
	if (nb < 0)
	{
		d_length += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		d_length += ft_putchar(nb + '0');
	else if (nb >= 10)
		d_length += ft_print_putnbr(nb);
	return (d_length);
}

int	print_lower_hexa(unsigned long c)
{
	int	length;

	length = 0;
	if (c >= 16)
	{
		length += print_lower_hexa(c / 16);
		length += print_lower_hexa(c % 16);
	}
	else if (c >= 10 && c <= 15)
		length += ft_putchar((c - 10 + 'a'));
	else 
		length += ft_putchar((c + '0'));
	return (length);
}

int	print_upper_hexa(unsigned long c)
{
	int	length;

	length = 0;
	if (c >= 16)
	{
		length += print_upper_hexa(c / 16);
		length += print_upper_hexa(c % 16);
	}
	else if (c >= 10 && c <= 15)
		length += ft_putchar((c - 10 + 'A'));
	else 
		length += ft_putchar((c + '0'));
	return (length);
}
