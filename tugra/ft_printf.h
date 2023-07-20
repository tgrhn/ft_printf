/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <42istanbul.com.tr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:31:46 by 42istanbu         #+#    #+#             */
/*   Updated: 2023/07/19 13:29:56 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char s);
int	ft_putstr(char *s);
int	ft_find_length(long c);
int	ft_print_putnbr(long c);
int	ft_putnbr(long nb);
int	print_lower_hexa(unsigned long c);
int	print_upper_hexa(unsigned long c);
int	ft_control(va_list args, char c);

#endif 
