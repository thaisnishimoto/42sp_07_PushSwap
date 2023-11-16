/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_radixsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 23:00:00 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
 * Function: count_binary_digits
 * --------------------
 * Counts the digits of the largest number in the stack in binary base.
 *
 * t_stack *a: A pointer to the t_stack structure that contains 
 *             the list of numbers in stack form.
 *
 * returns: the digits in the largest number from the stack.
 */

int	count_binary_digits(t_stack *a)
{
	int	i;
	int	d;
	int	d_max;
	int	num;

	i = 0;
	d_max = 0;
	while (i < a->top)
	{
		d = 0;
		num = a->items[i];
		while (num != 0)
		{
			num = num / 2;
			d++;
		}
		if (d > d_max)
			d_max = d;
		i++;
	}
	return (d_max);
}

/*
 * Function: opt_radixsort
 * --------------------
 * Performs an optimized radix sort on a stack of numbers.
 *
 * The function works by separating numbers based on their binary 0 bit 
 * and placing them in an auxiliary stack. It repeats this process for 
 * each digit in the numbers to be sorted.
 *
 * t_stack *a: A pointer to the t_stack structure that contains 
 *             the list of numbers to be sorted in stack form.
 * t_stack *b: A pointer to an empty t_stack structure that serves 
 *             as the auxiliary stack during sorting.
 *
 * The function modifies the input stack 'a' to be in sorted order.
 */

void	ft_opt_radixsort(t_stack *a, t_stack *b)
{
	int	digits;
	int	divisor;
	int	count;

	divisor = 1;
	ft_simplify_nums(a);
	digits = count_binary_digits(a);
	while (digits > 0)
	{
		count = a->top - 1;
		while (count >= 0)
		{
			if ((a->items[a->top - 1] / divisor) % 2 == 0)
				push_to_b(a, b);
			else
				rotate_a(a);
			count--;
		}
		while (b->top != 0)
			push_to_a(b, a);
		divisor *= 2;
		digits--;
	}
}
