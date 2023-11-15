/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:06:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/14 18:48:21 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top - 1)
	{
		if (a->items[i] > a->items[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

/*
 * Function: simplify_nums
 * --------------------
 * Changes a list of numbers so that it ranges from 0 to maxsize.
 * maxsize being the amount of numbers in the list
 *
 * t_stack a: struct that contains the list of numbers in stack form.
 *
 * The function modifies the input stack 'a' to be in smaller numbers.
 */

void	ft_simplify_nums(t_stack *a)
{
	int	*sorted_cpy;
	int	i;
	int	j;

	sorted_cpy = sort_cpy(a);
	i = 0;
	while (i < a->maxsize)
	{
		j = 0;
		while (a->items[i] != sorted_cpy[j])
			j++;
		a->items[i] = j;
		i++;
	}
	free(sorted_cpy);
}

/*
 * Function: sort_cpy
 * --------------------
 * Auxiliary function to simplify_nums, used to set an index for each num.
 * Sorts the list of numbers in ascending order, in a temporary array.
 *
 * t_stack *a: A pointer to the t_stack structure that contains 
 *             the list of numbers in stack form.
 *
 * returns: a copy of the numbers, sorted in ascending order.
 */

int	*sort_cpy(t_stack *a)
{
	int	*stack_cpy;
	int	i;
	int	j;

	stack_cpy = ft_calloc(a->top, sizeof(int));
	stack_cpy = ft_memcpy(stack_cpy, a->items, a->top * sizeof(int));
	i = 0;
	while (i < a->top - 1)
	{
		j = i + 1;
		while (j < a->top)
		{
			if (stack_cpy[i] > stack_cpy[j])
				ft_swap(&stack_cpy[i], &stack_cpy[j]);
			j++;
		}
		i++;
	}
	return (stack_cpy);
}

void	print_sequence(t_stack *stack)
{
	int	i;

	i = stack->top - 1;
	ft_printf("[top] ");
	while (i >= 0)
		ft_printf("%d ", stack->items[i--]);
	ft_printf("[bottom]");
	ft_printf("\n");

}

void	ft_free_matrix(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
