/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:34:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/10 18:37:24 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	partition_stack(t_stack *a, t_stack *b, int parts)
{
	int	part_size;
	int	pivot;
	int	count;
	int	i;

	part_size = a->maxsize / parts;
	pivot = part_size;
	while (parts > 1)
	{
		count = a->top - 1;
		while (count >= 0)
		{
			i = a->top - 1;
			while (a->items[i] > pivot)
			{
				i--;
				count--;
			}
			if (i >= 0)
			{
				ft_opt_move_to_top_a(a, a->items[i]);
				push_to_b(a, b);
				count--;
			}
		//	if (check_if_sorted(a) == 0)
		//		return ;
		}
		parts--;
		pivot += part_size;
	}
}

/*
 * Function: small_sort
 * --------------------
 * The sorting function works by pushing the smallest numbers from stack a to b
 * with the least amount of operations. When stack a has only 3 numbers left,
 * they are sorted in place. Finally, all numbers in stack b are pushed back
 * to a. They are already in sorted order due to the previous operations.
 *
 * t_stack *a: A pointer to the t_stack structure that contains 
 *             up to 10 unsorted numbers to be sorted in stack form.
 * t_stack *b: A pointer to a t_stack structure that contains 
 *             an auxiliary empty stack.
 *
 * The function modifies the input stack 'a' to be in sorted order.
 */

void	ft_quicksort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	ft_simplify_nums(a);
	if (a->maxsize <= 50)
		partition_stack(a, b, 2);
	else if (a->maxsize > 50 && a->maxsize <= 200)
		partition_stack(a, b, 5);
	else
		partition_stack(a, b, 13);
	while (a->top > 3)
	{
		min = ft_get_min(a);
		ft_opt_move_to_top_a(a, min);
		push_to_b(a, b);
	}
	ft_sort_3(a);
	while (b->top != 0)
	{
		max = ft_get_max(b);
		ft_opt_move_to_top_b(b, max);
		push_to_a(b, a);
	}
}
