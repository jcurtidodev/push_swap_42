/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:04:14 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/03 19:56:33 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned char	uc;

	p = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			p = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (p);
}
