/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:34:03 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 18:38:52 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	swapped;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		swapped = 0;
		while (j < size)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			return ;
		i++;
	}
}

size_t	assign_index(t_num **stack, int *sorted_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (*stack[i]->num == sorted_array[j])
			{
				stack[i]->index = malloc(sizeof(unsigned int));
				if (!stack[i]->index)
					return (0);
				*stack[i]->index = j;
			}
			j++;
		}
		i++;
	}
	return (1);
}

size_t	manage_index(t_num **stack, int size)
{
	int		*sorted_array;
	int		i;
	size_t		flag;

	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
		return (0);
	i = 0;
	while (i < size)
	{
		sorted_array[i] = *stack[i]->num;
		i++;
	}
	bubble_sort(sorted_array, size);
	flag = assign_index(stack, sorted_array, size);
	free(sorted_array);
	return (flag);
}
