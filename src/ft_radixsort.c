/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/01 14:39:34 by tmina-ni         ###   ########.fr       */
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
//int	count_digits(t_stack *a, int base, int *neg_flag)
//{
//	int	i;
//	int	max_pos;
//	int	min_pos;
//	int	d_max;
//	int	d_min;
//
//	i = 0;
//	max_pos = 0;
//	while (i < a->maxsize)
//	{
//		if (a->items[i] > a->items[max_pos])
//			max_pos = i;
//		if (a->items[i] < a->items[min_pos])
//			min_pos = i;
//		i++;
//	}
//	if (a->items[min_pos] < 0)
//		neg_flag = 1;
//	d_max = 0;
//	while (a->items[max_pos] != 0)
//	{
//		max_num = max_num / base;
//		d_max++;
//	}
//	d_min = 0;
//	while (max_num != 0)
//	{
//		max_num = max_num / base;
//		d_max++;
//	}
//	return (d);
//}

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
				temp = a->items[a->top - 1] * (- 1);
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
				temp = b->items[b->top - 1] * (- 1);
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

void	ft_radix_sort(t_stack *a, t_stack *b, int base)
{
	int	digits;
	int	divisor;
	int	i;
	int	neg_flag;
	int	count;

	divisor = 1;
	i = 1;
	neg_flag = 0;
	digits = count_digits(a, base, &neg_flag);
//	ft_printf("digits: %d\n", digits);
	while (i <= digits)
	{
//		ft_printf("i: %d\n", i);
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
	count = 0;
	if (digits % 2 == 0)
	{
		if (neg_flag == 1)
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
		while (b->top != 0)
			push_to_a(b, a);
	}
	else
	{
		if (neg_flag == 1)
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
		}
		while (b->top != 0)
		{
			rotate_b(b);
			push_to_a(b, a);
		}
	}
}
