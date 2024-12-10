/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:15:11 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 16:27:25 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft/libft.h"

// Estructura de listas

typedef struct s_num
{
	int				*num;
	unsigned int	*index;
}	t_num;

// Executable utils
void	print_stack(t_num **stack, int size);// TO DELETE
//int   return_free_error(t_num **stack, char *message, int size); // TO IMPLEMENT AT MAIN
void	free_stack(t_num **stack, int i);
t_num	**create_stack(int len);
size_t	parse_numbers(int argc, char *argv[], t_num **stack);
size_t	check_repeated(int size, t_num **stack);
size_t	is_sorted(t_num **stack, int size);

// Index utils
void	bubble_sort(int *arr, int size);
size_t	assign_index(t_num **stack, int *sorted_array, int size);
size_t	manage_index(t_num **stack, int size);

// Push Swap utils
void	print_move(void);// pendiente

// Ordenation
//void	sort_small_stack(t_num **stack_a, t_num **stack_b);// pendiente
//void	sort_big_stack(t_num **stack_a, t_num **stack_b);// pendiente
void	push_swap(t_num **stack, int size);//pendiente

// Movements
void	swap(t_num **stack);
void	rotate(t_num **stack, int size);
void	reverse_rotate(t_num **stack, int size);
void	push_from_to(t_num **stack_1, t_num **stack_2, int size);

#endif
