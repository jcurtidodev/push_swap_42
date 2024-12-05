/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:29:14 by jcurtido          #+#    #+#             */
/*   Updated: 2024/11/13 16:11:24 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_check_variables(char c, va_list args)
{
	if (c == 'c')
		return (split_putchr((char)va_arg(args, int)));
	else if (c == 's')
		return (split_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (split_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (split_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (split_putunbr_hex(va_arg(args, unsigned int), c));
	else if (c == 'x' || c == 'X')
		return (split_putunbr_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (split_putpct());
	else
	{
		ft_putchar_fd('%', 1);
		if (c == 'k' || c == 'r' || c == 'v' || c == 'w'
			|| c == 'y')
			return (ft_putchar_fd(c, 1), 2);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			len++;
		}
		else if (format[i + 1])
		{
			len += split_check_variables(format[i + 1], args);
			i ++;
		}
		else if (!format[i + 1])
			return (-1);
		i++;
	}
	va_end(args);
	return (len);
}
