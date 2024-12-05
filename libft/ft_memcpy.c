/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:34:40 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/15 14:18:04 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*sp;
	unsigned char	*dp;

	if (!dest && !src && count > 0)
		return (NULL);
	if (count == 0)
		return (dest);
	sp = (unsigned char *)src;
	dp = (unsigned char *)dest;
	while (count--)
		*dp++ = *sp++;
	return (dest);
}
