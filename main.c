/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:36:12 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 18:16:56 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	t_num		**stack;
	size_t		parsed;
	size_t		repeated;
	size_t		sorted;

	if (argc <= 2)
		return (1);
	stack = create_stack(argc - 1);
	if (!stack)
		return (free_stack(stack, argc - 1), ft_printf("Assignation memory error\n"), 1);
	parsed = parse_numbers(argc - 1, argv, stack);
	if (!parsed)
		return (free_stack(stack, argc - 1), ft_printf("Invalid input\n"), 1);
	if (!manage_index(stack, argc - 1))
		return (free_stack(stack, argc - 1), ft_printf("Can not index the numbers"), 1);
	repeated = check_repeated(argc - 1, stack);
	if (repeated)
		return (free_stack(stack, argc - 1), ft_printf("There are repeated numbers\n"), 1);
	sorted = is_sorted(stack, argc - 1);
	if (sorted)
		return (free_stack(stack, argc - 1), ft_printf("The numbers are sorted\n"), 1);
	push_swap(stack, argc - 1);
	free_stack(stack, argc - 1);
	return (0);
}
