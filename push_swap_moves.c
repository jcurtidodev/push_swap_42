/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:43:47 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 17:48:10 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_num **stack)
{
	int	temp_nb;
	unsigned int	temp_idx;

	temp_nb = *stack[0]->num;
	temp_idx = *stack[0]->index;
	*stack[0]->num = *stack[1]->num;
	*stack[0]->index = *stack[1]->index;
	*stack[1]->num = temp_nb;
	*stack[1]->index = temp_idx;
}

void	rotate(t_num **stack, int size)
{
	int	i;
	int	temp_nb;
	unsigned int	temp_idx;

	if (size <= 1)
		return ;
	i = 0;
	temp_nb = *stack[i]->num;
	temp_idx = *stack[i]->index;
	while (i < size - 1)
	{
		*stack[i]->num = *stack[i + 1]->num;
                *stack[i]->index = *stack[i + 1]->index;
		i++;
	}
	*stack[i]->num = temp_nb;
	*stack[i]->index = temp_idx;
}

void	reverse_rotate(t_num **stack, int size)
{
	int	i;
	int	temp_nb;
	unsigned int	temp_idx;

	if (size <= 1)
		return ;
	i = size - 1;
	temp_nb = *stack[i]->num;
	temp_idx = *stack[i]->index;
	while (i > 0)
	{
		*stack[i]->num = *stack[i - 1]->num;
		*stack[i]->index = *stack[i - 1]->index;
		i--;
	}
	*stack[i]->num = temp_nb;
	*stack[i]->index = temp_idx;
}

void	push_from_to(t_num **stack_1, t_num **stack_2, int size)
{
	int	i;
	int	j;

	if (stack_1[size - 1]->num == NULL)
		return ;
	i = 0;
	j = size - 1;
	while (stack_1[i]->num == NULL && i < size - 1)
		i++;
	while (stack_2[j]->num != NULL && j > 0)
		j--;
	stack_2[j]->num = malloc(sizeof(int));
	stack_2[j]->index = malloc(sizeof(unsigned int));
	if (!stack_2[j]->num || !stack_2[j]->index)
		return ;
	*stack_2[j]->num = *stack_1[i]->num;
	*stack_2[j]->index = *stack_1[i]->index;
	free(stack_1[i]->num);
	free(stack_1[i]->index);
	stack_1[i]->num = NULL;
	stack_1[i]->index = NULL;
}
