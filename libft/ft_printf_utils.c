/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:01:28 by jcurtido          #+#    #+#             */
/*   Updated: 2024/11/13 16:11:36 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_var(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == '%');
}

size_t	split_putchr(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	split_putstr(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1), 6);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	split_putnbr(int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
