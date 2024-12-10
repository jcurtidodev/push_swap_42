/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:02:30 by jcurtido          #+#    #+#             */
/*   Updated: 2024/12/05 18:37:42 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//to delete
void	print_stack(t_num **stack, int size)
{
	int	i = 0;
	while (i < size)
	{
                if (stack[i]->num == NULL)
                        ft_printf("|||| stack[%d]->num = NULL ||||\n", i);
                else
                        ft_printf("|||| stack[%d]->num = %d ||||\n", i, *stack[i]->num);
                if (stack[i]->index == NULL)
                        ft_printf("|||| stack[%d]->index = NULL ||||\n\n", i);
                else
                        ft_printf("|||| stack[%d]->index = %d ||||\n\n", i, *stack[i]->index);
                i++;

	}
}

void	free_stack(t_num **stack, int len)
{
        if (!stack)
                return ;
        while (size >= 0)
        {
                if (stack[size])
                {
                        if (stack[size]->num)
                                free(stack[size]->num);
                        if (stack[size]->index)
                                free(stack[size]->index);
                        stack[size]->num = NULL;
                        stack[size]->index = NULL;
                        free(stack[size]);
                        stack[size] = NULL;
                }
        	size--;
        }
        free(stack);
	stack = NULL;

}

t_num	**create_stack(int len)
{
	t_num	**stack;
	int		i;

	stack = malloc(len * sizeof(t_num *));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack[i] = malloc(sizeof(t_num));
		if (!stack[i])
			return (free_stack(stack, i), NULL);
		stack[i]->num = NULL;
		stack[i]->index = NULL;
		i++;
	}
	return (stack);
}

size_t	parse_numbers(int len, char *argv[], t_num **stack)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_atoi(argv[i + 1]) == 0 && argv[i + 1][0] != '0')
			return (free_stack(stack, len), 0);
		stack[i]->num = malloc(sizeof(int));
		if (!stack[i]->num)
			return (free_stack(stack, len), 0);
		*stack[i]->num = ft_atoi(argv[i + 1]);
		i++;
	}
	return (1);
}

size_t	check_repeated(int size, t_num **stack)
{
	int		i;
	int		j;
	size_t	repeated;

	i = 0;
	repeated = 0;
	while (i < size && repeated == 0)
	{
		j = 0;
		while (j < size && repeated == 0)
		{
			if (i == j)
				j++;
			if (j >= size)
				return (repeated);
			if (*stack[j]->num == *stack[i]->num)
				repeated = 1;
			j++;
		}
		i++;
	}
	return (repeated);
}

size_t	is_sorted(t_num **stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (*stack[i - 1]->num > *stack[i]->num)
			return (0);
		i++;
	}
	return (1);
}
