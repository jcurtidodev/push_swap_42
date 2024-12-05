/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:48:10 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/03 15:47:09 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	split_get_length(long int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*split_fill_string(char *str, size_t len,
	size_t is_negative, long int n)
{
	size_t	i;
	int		divisor;
	int		temp;

	i = 0;
	divisor = 1;
	temp = len;
	if (is_negative)
	{
		str[i] = '-';
		i++;
	}
	while (temp-- > 1)
		divisor *= 10;
	while (i < (len + is_negative))
	{
		str[i] = (n / divisor) + '0';
		n = n % divisor;
		divisor /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	size_t		is_negative;
	long int	long_n;

	long_n = (long int)n;
	is_negative = 0;
	if (long_n < 0)
	{
		is_negative++;
		long_n *= -1;
	}
	len = split_get_length(long_n);
	str = (char *)malloc((len + 1 + is_negative) * sizeof(char));
	if (!str)
		return (NULL);
	str = split_fill_string(str, len, is_negative, long_n);
	return (str);
}
