/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:34:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 23:25:36 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	process_partition(t_stack *a, t_stack *b, int count, int pivot)
{
	int	i;

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
			ft_opt_move_to_top_a(a, &i);
			push_to_b(a, b);
			count--;
		}
	}
}

void	partition_stack(t_stack *a, t_stack *b, int parts)
{
	int	part_size;
	int	pivot;
	int	count;

	part_size = a->maxsize / parts;
	pivot = part_size;
	while (parts > 1)
	{
		count = a->top - 1;
		process_partition(a, b, count, pivot);
		parts--;
		pivot += part_size;
	}
}

void	ft_quicksort(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	max_pos;

	ft_simplify_nums(a);
	if (a->maxsize <= 50)
		partition_stack(a, b, 2);
	else if (a->maxsize > 50 && a->maxsize <= 200)
		partition_stack(a, b, 5);
	else
		partition_stack(a, b, 13);
	while (a->top > 3)
	{
		min_pos = ft_get_min_pos(a);
		ft_opt_move_to_top_a(a, &min_pos);
		push_to_b(a, b);
	}
	ft_sort_3(a);
	while (b->top != 0)
	{
		max_pos = ft_get_max_pos(b);
		ft_opt_move_to_top_b(b, &max_pos);
		push_to_a(b, a);
	}
}
