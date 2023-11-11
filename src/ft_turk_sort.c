/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:39:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/11 11:18:58 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_to_top(t_stack *stack, int num_pos)
{
	int median;
	int	moves;

	median = stack->top / 2;
	moves = 0;
	if (num_pos > median)
		moves = stack->top - num_pos;
	else
		moves = num_pos;
	return (moves);
}

int calculate_cost_to_target(t_stack *a, t_stack *b, int num_pos)
{
	int target_pos;
	int moves;

	target_pos = a->top - 1;
	while (b->items[i])
	moves = cost_to_top(b, num_pos);
}

void	find_cheapest_num(t_stack *a, t_stack *b);
{
	int curr_pos;
	int	target_pos;
	int	move_cost;
	int	i;

	cost_current_pos_to_top;
	cost_right_pos_to_top;
	moves = 0;
	i = a->top - 1;
	pos = i;
	while (i >= 0)
	{
		moves = count_bring_top(a, i);
	}
}

void	ft_turk_sort(t_stack *a, t_stack *b)
{
	int	cheap_pos;
	int	min;

	while (a->top > 3)
		push_to_b(a, b);
	ft_sort_3(a);
	while (b->top != 0)
	{
		find_cheapest_num();
		push_cheapest_to_a(b, a, num);
	}
	min = ft_get_min(a)
	ft_opt_move_to_top_a(a, min);
}
