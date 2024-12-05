/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:15:41 by jcurtido          #+#    #+#             */
/*   Updated: 2024/11/13 16:11:50 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_print_ptr(unsigned long nb, char *base)
{
	size_t	count;
	char	c;

	count = 0;
	if (nb >= 16)
		count += split_print_ptr(nb / 16, base);
	c = base[nb % 16];
	write(1, &c, 1);
	return (count + 1);
}

size_t	split_putptr(void *ptr)
{
	unsigned long	address;
	size_t			count;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += split_print_ptr(address, "0123456789abcdef");
	return (count);
}

size_t	split_putunbr_hex(unsigned int n, char c)
{
	long	nb;
	char	*str;
	size_t	len;

	nb = (long)n;
	str = ft_itoa_base(nb, c);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

size_t	split_putpct(void)
{
	write(1, "%", 1);
	return (1);
}
