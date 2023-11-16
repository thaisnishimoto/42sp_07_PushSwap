/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find_cheapest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:39:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:12 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_target_pos(t_stack *a, int num, t_stack *b)
{
	int	*stack_cpy;
	int	i;
	int	target_pos;

	stack_cpy = sort_cpy_stack(a);
	if (stack_cpy == NULL)
		ft_handle_error(a, b, 3, NULL);
	i = a->top - 1;
	while (i >= 0 && num > stack_cpy[i])
		i--;
	if (i < 0)
		i = a->top - 1;
	target_pos = a->top - 1;
	while (a->items[target_pos] != stack_cpy[i])
		target_pos--;
	free(stack_cpy);
	return (target_pos);
}

int	*sort_cpy_stack(t_stack *a)
{
	int	*stack_cpy;
	int	i;
	int	j;

	stack_cpy = ft_calloc(a->top, sizeof(int));
	if (stack_cpy == NULL)
		return (NULL);
	stack_cpy = ft_memcpy(stack_cpy, a->items, a->top * sizeof(int));
	i = 0;
	while (i < a->top - 1)
	{
		j = i + 1;
		while (j < a->top)
		{
			if (stack_cpy[i] < stack_cpy[j])
				ft_swap(&stack_cpy[i], &stack_cpy[j]);
			j++;
		}
		i++;
	}
	return (stack_cpy);
}

int	cost_to_target(t_stack *a, t_stack *b, int num_pos, int target_pos)
{
	int	moves;

	moves = 0;
	if (target_pos > a->top / 2 && num_pos > b->top / 2)
	{
		while (target_pos != a->top - 1 && num_pos != b->top - 1)
		{
			moves++;
			num_pos++;
			target_pos++;
		}
	}
	else if (target_pos < a->top / 2 && num_pos < b->top / 2)
	{
		while (target_pos >= 0 && num_pos >= 0)
		{
			moves++;
			num_pos--;
			target_pos--;
		}
	}
	moves += cost_to_top(b, &num_pos);
	moves += cost_to_top(a, &target_pos);
	return (moves + 1);
}

int	cost_to_top(t_stack *stack, int *num_pos)
{
	int	median;
	int	moves;

	median = stack->top / 2;
	moves = 0;
	if (*num_pos < median)
	{
		while (*num_pos >= 0)
		{
			moves++;
			(*num_pos)--;
		}
	}
	else
	{
		while (*num_pos < stack->top - 1)
		{
			moves++;
			(*num_pos)++;
		}
	}
	return (moves);
}

int	find_cheapest_num(t_stack *a, t_stack *b)
{
	int	*move_cost;
	int	i;
	int	target_pos;
	int	cheapest_pos;

	move_cost = ft_calloc(b->top, sizeof(int));
	if (move_cost == NULL)
		ft_handle_error(a, b, 3, NULL);
	i = 0;
	while (i < b->top)
	{
		target_pos = find_target_pos(a, b->items[i], b);
		move_cost[i] = cost_to_target(a, b, i, target_pos);
		i++;
	}
	cheapest_pos = --i;
	while (i >= 0)
	{
		if (move_cost[cheapest_pos] > move_cost[i])
			cheapest_pos = i;
		i--;
	}
	free(move_cost);
	return (cheapest_pos);
}
