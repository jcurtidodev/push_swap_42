/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:28:46 by jcurtido          #+#    #+#             */
/*   Updated: 2024/11/13 15:59:11 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_get_base_digits(char c)
{
	char	*digits;

	digits = "0123456789";
	if (c == 'p' || c == 'x')
		digits = "0123456789abcdef";
	else if (c == 'X')
		digits = "0123456789ABCDEF";
	return (digits);
}

static size_t	split_get_length(long int n, char *digits)
{
	size_t	count;
	size_t	base_len;

	if (n == 0)
		return (1);
	count = 0;
	base_len = ft_strlen(digits);
	while (n > 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

static char	*split_fill_string(char *str, size_t is_negative,
		long int n, char *digits)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		temp;

	i = 0;
	len = split_get_length(n, digits);
	while (len-- > 0)
	{
		str[i++] = digits[n % ft_strlen(digits)];
		n /= ft_strlen(digits);
	}
	if (is_negative)
		str[i++] = '-';
	j = 0;
	while (j < i / 2)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(long nb, char c)
{
	char		*str;
	size_t		is_negative;
	long int	long_n;
	char		*digits;

	is_negative = 0;
	long_n = nb;
	if (!(c == 'd' || c == 'i'))
		long_n = (unsigned int)nb;
	else if (c == 'p')
		long_n = (unsigned long)nb;
	digits = split_get_base_digits(c);
	if (long_n < 0 && ft_strlen(digits) == 10)
	{
		if (c != 'u')
			is_negative++;
		long_n *= -1;
	}
	str = (char *)malloc((split_get_length(long_n, digits) + 1 + is_negative)
			* sizeof(char));
	if (!str)
		return (NULL);
	str = split_fill_string(str, is_negative, long_n, digits);
	return (str);
}
