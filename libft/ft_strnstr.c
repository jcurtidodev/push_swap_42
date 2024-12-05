/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:18:35 by jcurtido          #+#    #+#             */
/*   Updated: 2024/09/23 19:41:03 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str == '\0')
		return ((char *)src);
	while (i < len && src[i])
	{
		j = 0;
		while (src[i + j] == str[j] && (i + j) < len)
		{
			if (str[j + 1] == '\0')
				return ((char *)(src + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
