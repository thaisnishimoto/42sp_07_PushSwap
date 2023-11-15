/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:02:27 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 16:51:56 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->items[i];
	while (i < stack->top - 1)
	{
		if (stack->items[i + 1] < min)
			min = stack->items[i + 1];
		i++;
	}
	return (min);
}

int	ft_get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->items[i];
	while (i < stack->top - 1)
	{
		if (stack->items[i + 1] > max)
			max = stack->items[i + 1];
		i++;
	}
	return (max);
}

void	ft_opt_move_to_top_a(t_stack *a, int num)
{
	int	num_pos;

	num_pos = 0;
	while (a->items[num_pos] != num)
		num_pos++;
	if (num_pos < a->top / 2)
	{
		while (num_pos >= 0)
		{
			reverse_a(a);
			num_pos--;
		}
	}
	else
	{
		while (num_pos < a->top - 1)
		{
			rotate_a(a);
			num_pos++;
		}
	}
}

void	ft_opt_move_to_top_b(t_stack *b, int *num_pos)
{
//	int	num_pos;
//
//	num_pos = 0;
//	while (b->items[num_pos] != num)
//		num_pos++;
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
	int	min;
	int	max;

	if (check_if_sorted(a) == 0)
		return ;
	min = ft_get_min(a);
	max = ft_get_max(a);
	if (a->items[a->top - 1] == min)
	{
		swap_a(a);
		rotate_a(a);
	}	
	else if (a->items[a->top - 1] == max)
	{
		rotate_a(a);
		if (a->items[a->top - 1] != min)
			swap_a(a);
	}
	else
	{
		if (a->items[0] == max)
			swap_a(a);
		else
			reverse_a(a);
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

void	ft_small_sort(t_stack *a, t_stack *b)
{
	int	min;

	while (a->top > 3)
	{
		min = ft_get_min(a);
		ft_opt_move_to_top_a(a, min);
		push_to_b(a, b);
	}
	if (a->top == 3)
		ft_sort_3(a);
	else if (a->top == 2)
		rotate_a(a);
	while (b->top != 0)
		push_to_a(b, a);
}
