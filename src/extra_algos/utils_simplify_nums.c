/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simplify_nums.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:06:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 23:00:56 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
