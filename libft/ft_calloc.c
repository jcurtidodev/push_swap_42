/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:19:20 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/03 15:16:17 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*memory;

	if (num_elements == 0 || element_size == 0)
		return (malloc(0));
	if (element_size > (size_t)-1 / num_elements)
		return (NULL);
	memory = malloc(num_elements * element_size);
	if (!memory)
		return (NULL);
	return (ft_memset(memory, 0, num_elements * element_size));
}
