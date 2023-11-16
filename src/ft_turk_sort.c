/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:39:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 12:26:48 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_cheapest_to_a(t_stack *b, t_stack *a, int num_pos)
{
	int	target_pos;

	target_pos = find_target_pos(a, b->items[num_pos], b);
	if (target_pos > a->top / 2 && num_pos > b->top / 2)
	{
		while (target_pos != a->top - 1 && num_pos != b->top - 1)
		{
			rotate_both(a, b);
			num_pos++;
			target_pos++;
		}
	}
	else if (target_pos < a->top / 2 && num_pos < b->top / 2)
	{
		while (target_pos >= 0 && num_pos >= 0)
		{
			reverse_both(a, b);
			num_pos--;
			target_pos--;
		}
	}
	ft_opt_move_to_top_b(b, &num_pos);
	ft_opt_move_to_top_a(a, &target_pos);
	push_to_a(b, a);
}

int	ft_get_min_pos(t_stack *stack)
{
	int	i;
	int	min_pos;

	i = 0;
	min_pos = i;
	while (i < stack->top)
	{
		if (stack->items[i] < stack->items[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

void	ft_opt_move_to_top_a(t_stack *a, int *num_pos)
{
	if (*num_pos < a->top / 2)
	{
		while (*num_pos >= 0)
		{
			reverse_a(a);
			(*num_pos)--;
		}
	}
	else
	{
		while (*num_pos < a->top - 1)
		{
			rotate_a(a);
			(*num_pos)++;
		}
	}
}

void	ft_opt_move_to_top_b(t_stack *b, int *num_pos)
{
	if (*num_pos < b->top / 2)
	{
		while (*num_pos >= 0)
		{
			reverse_b(b);
			(*num_pos)--;
		}
	}
	else
	{
		while (*num_pos < b->top - 1)
		{
			rotate_b(b);
			(*num_pos)++;
		}
	}
}

void	ft_turk_sort(t_stack *a, t_stack *b)
{
	int	num_pos;
	int	min_pos;

	while (a->top > 3)
		push_to_b(a, b);
	ft_sort_3(a);
	while (b->top != 0)
	{
		num_pos = find_cheapest_num(a, b);
		push_cheapest_to_a(b, a, num_pos);
	}
	min_pos = ft_get_min_pos(a);
	ft_opt_move_to_top_a(a, &min_pos);
}
