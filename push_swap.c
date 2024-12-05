/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:11 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 18:12:21 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_num **stack_a, t_num **stack_b)
{
	stack_a = NULL;
	stack_b = NULL;
	return ;
}

void	sort_big_stack(t_num **stack_a, t_num **stack_b)
{
	stack_a = NULL;
	stack_b = NULL;
	return ;
}

void	push_swap(t_num **stack_a, int size)
{
	t_num	**stack_b;

	stack_b = create_stack(size);
	ft_printf("++++ INITIAL ARRAY ++++\n");
	print_stack(stack_a, size);
	ft_printf("\n++++ARRAY AFTER SWAP++++\n");
	swap(stack_a);
	print_stack(stack_a, size);
	ft_printf("\n++++ARRAY AFTER ROTATE++++\n");
	rotate(stack_a, size);
	print_stack(stack_a, size);
	ft_printf("\n++++ARRAY AFTER REVERSE ROTATE++++\n");
	reverse_rotate(stack_a, size);
	print_stack(stack_a, size);
	ft_printf("\n++++ARRAY ||A|| AFTER PUSH TO B 2 TIMES++++\n");
	push_from_to(stack_a, stack_b, size);
	push_from_to(stack_a, stack_b, size);
	print_stack(stack_a, size);
	ft_printf("\n++++ARRAY ||B|| AFTER PUSH TO B++++\n");
	push_from_to(stack_b, stack_a, size);
	print_stack(stack_b, size);
	free_stack(stack_b, size);
}
