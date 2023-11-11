/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/07 14:53:33 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_digits(t_stack *a, int base, int *neg_flag)
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
		if (num < 0)
			*neg_flag = 1;
		while (num != 0)
		{
			num = num / base;
			d++;
		}
		if (d > d_max)
			d_max = d;
		i++;
	}
	return (d_max);
}

void	sort_bit_stack_a(t_stack *a, t_stack *b, int base, int divisor)
{
	int	bit;
	int	count;
	int	temp;

	bit = 0;
	while (bit < base)
	{
		count = a->top - 1;
		while (count >= 0)
		{
			if (a->items[a->top - 1] < 0)
				temp = a->items[a->top - 1] * (-1);
			else
				temp = a->items[a->top - 1];
			if ((temp / divisor) % base == bit)
				push_to_b(a, b);
			else
				rotate_a(a);
			count--;
		}
		bit++;
	}
}

void	sort_bit_stack_b(t_stack *b, t_stack *a, int base, int divisor)
{
	int	bit;
	int	count;
	int	temp;

	bit = base - 1;
	while (bit >= 0)
	{
		count = b->top - 1;
		while (count >= 0)
		{
			if (b->items[b->top - 1] < 0)
				temp = b->items[b->top - 1] * (-1);
			else
				temp = b->items[b->top - 1];
			if ((temp / divisor) % base == bit)
				push_to_a(b, a);
			else
				rotate_b(b);
			count--;
		}
		bit--;
	}
}

void	handle_neg_nums(t_stack *a, t_stack *b, int digits)
{
	int	count;

	if (digits % 2 == 0)
	{
		count = a->top - 1;
		while (count >= 0)
		{
			reverse_a(a);
			if (a->items[a->top - 1] < 0)
				push_to_b(a, b);
			count--;
		}
	}
	else
	{
		count = b->top - 1;
		while (count >= 0)
		{
			if (b->items[b->top - 1] >= 0)
				push_to_a(b, a);
			else
				rotate_b(b);
			count--;
		}
		while (b->top != 0)
		{
			reverse_b(b);
			push_to_a(b, a);
		}
	}
}

void	ft_radixsort(t_stack *a, t_stack *b, int base)
{
	int	digits;
	int	divisor;
	int	i;
	int	neg_flag;

	divisor = 1;
	i = 1;
	neg_flag = 0;
	digits = count_digits(a, base, &neg_flag);
	while (i <= digits)
	{
		if (i % 2 != 0)
		{
			sort_bit_stack_a(a, b, base, divisor);
			divisor *= base;
			i++;
		}
		else
		{
			sort_bit_stack_b(b, a, base, divisor);
			divisor *= base;
			i++;
		}
	}
	if (neg_flag == 1)
		handle_neg_nums(a, b, digits);
	while (b->top != 0)
		push_to_a(b, a);
}
