/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:57:12 by jcurtido          #+#    #+#             */
/*   Updated: 2024/09/23 19:38:31 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	temp;
	size_t	len;
	size_t	i;

	temp = 0;
	len = 0;
	while (dest[temp] && temp < dstsize)
		temp++;
	while (src[len])
		len++;
	if (temp >= dstsize)
		return (dstsize + len);
	i = 0;
	while (src[i] && (temp + i) < (dstsize - 1))
	{
		dest[temp + i] = src[i];
		i++;
	}
	dest[temp + i] = '\0';
	return (temp + len);
}
