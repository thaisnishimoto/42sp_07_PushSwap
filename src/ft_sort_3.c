/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:02:27 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 15:19:07 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_max_pos(t_stack *stack)
{
	int	i;
	int	max_pos;

	i = 0;
	max_pos = i;
	while (i < stack->top)
	{
		if (stack->items[i] > stack->items[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

/*
 * Function: sort_3
 * --------------------
 * The function works by checking all possible unsorted combinations 
 * of 3 numbers and individualy sorting them 
 *
 * t_stack *a: A pointer to the t_stack structure that contains 
 *             3 unsorted numbers to be sorted in stack form.
 *
 * The function modifies the input stack 'a' to be in sorted order.
 */

void	ft_sort_3(t_stack *a)
{
	int	min_pos;
	int	max_pos;

	if (check_if_sorted(a) == 0)
		return ;
	min_pos = ft_get_min_pos(a);
	max_pos = ft_get_max_pos(a);
	if (min_pos == a->top - 1)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (max_pos == a->top - 1)
	{
		rotate_a(a);
		if (min_pos == 0)
			swap_a(a);
	}
	else
	{
		if (max_pos == 0)
			swap_a(a);
		else
			reverse_a(a);
	}
}
