/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:39:45 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 16:52:24 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	*sort_cpy_stack(t_stack *a)
{
	int	*stack_cpy;
	int	i;
	int	j;

	stack_cpy = ft_calloc(a->top, sizeof(int));
	stack_cpy = ft_memcpy(stack_cpy, a->items, a->top * sizeof(int));
	min = ft_get_min(stack_cpy);
	if (num_pos < a->top / 2)
	{
		while (num_pos >= 0)
		{
			reverse_b(b);
			num_pos--;
		}
	}
	else
	{
		while (num_pos < b->top - 1)
		{
			rotate_b(b);
			num_pos++;
		}
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

int	find_target_pos(t_stack *a, int num)
{
	int	*stack_cpy;
	int	i;
	int	target_pos;

	stack_cpy = sort_cpy_stack(a);
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

int	calculate_cost_to_target(t_stack *a, t_stack *b, int num_pos)
{
	int	target_pos;
	int	moves;
	int	median_a;
	int	median_b;

	median_a = a->top / 2;
	median_b = b->top / 2;
	moves = 0;
	target_pos = find_target_pos(a, b->items[num_pos]);
	while (num_pos >= 0 && num_pos != b->top - 1)
	{
		if (target_pos >= 0 && target_pos != a->top - 1)
		{
			if (target_pos > median_a && num_pos > median_b)
			{
				moves++;
				num_pos++;
				target_pos++;
			}
			else if (target_pos < median_a && num_pos < median_b)
			{
				moves++;
				num_pos--;
				target_pos--;
			}
			else
				moves += cost_to_top(b, &num_pos);
		}
		else
			moves += cost_to_top(b, &num_pos);
	}
	moves += cost_to_top(a, &target_pos);
	return (moves);
}

int	find_cheapest_num(t_stack *a, t_stack *b)
{
	int	*move_cost;
	int	i;
	int	cheapest_pos;

	move_cost = ft_calloc(b->top, sizeof(int));
	if (move_cost == NULL)
	{
		//free stacks
		write(2, "Error\n", 6);
	}
	i = 0;
	while (i < b->top)
	{
		move_cost[i] = calculate_cost_to_target(a, b, i);
		i++;
	}
	i--;
	cheapest_pos = i;
	while (i >= 0)
	{
		if (move_cost[cheapest_pos] > move_cost[i])
			cheapest_pos = i;
		i--;
	}
	free(move_cost);
//	ft_printf("cheapest = %d\n", b->items[cheapest_pos]);
	return (cheapest_pos);
}

void	push_cheapest_to_a(t_stack *b, t_stack *a, int num_pos)
{
	int	median_a;
	int	median_b;
	int	target_pos;

	target_pos = find_target_pos(a, b->items[num_pos]);
	median_a = a->top / 2;
	median_b = b->top / 2;
	while (num_pos >= 0 && num_pos != b->top - 1)
	{
		if (target_pos >= 0 && target_pos != a->top - 1)
		{
			if (target_pos > median_a && num_pos > median_b)
			{
				rotate_both(a, b);
				num_pos++;
				target_pos++;
			}
			else if (target_pos < median_a && num_pos < median_b)
			{
				reverse_both(a, b);
				num_pos--;
				target_pos--;
			}
			else
			{
				if (num_pos < b->top / 2)
				{
					while (num_pos >= 0)
					{
						reverse_b(b);
						num_pos--;
					}
				}
				else
				{
					while (num_pos < b->top - 1)
					{
						rotate_b(b);
						num_pos++;
					}
				}
			}
		}
		else
		{
			if (num_pos < b->top / 2)
			{
				while (num_pos >= 0)
				{
					reverse_b(b);
					num_pos--;
				}
			}
			else
			{
				while (num_pos < b->top - 1)
				{
					rotate_b(b);
					num_pos++;
				}
			}
		}
//			ft_opt_move_to_top_b(b, b->items[num_pos]);
	}
	ft_opt_move_to_top_a(a, a->items[target_pos]);
	push_to_a(b, a);
}

void	ft_turk_sort(t_stack *a, t_stack *b)
{
	int	num_pos;
	int	min;

	while (a->top > 3)
		push_to_b(a, b);
	ft_sort_3(a);
	while (b->top != 0)
	{
		num_pos = find_cheapest_num(a, b);
		push_cheapest_to_a(b, a, num_pos);
	}
	min = ft_get_min(a);
	ft_opt_move_to_top_a(a, min);
}
