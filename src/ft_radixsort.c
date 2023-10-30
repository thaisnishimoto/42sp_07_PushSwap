/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/30 13:37:51 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_digits(t_stack *a)
{
	int	i;
	int	max_pos;
	int	max_num;
	int	d;

	i = 0;
	max_pos = 0;
	while (i < a->maxsize)
	{
		if (a->items[i] > a->items[max_pos])
			max_pos = i;
		i++;
	}
	max_num = a->items[max_pos];
	d = 0;
	while (max_num != 0)
	{
		max_num = max_num / 10;
		d++;
	}
	return (d);
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	d;
	int	bit;
	int	count;
	int	temp;
	int	divisor;

	divisor = 1;
	d = find_digits(a);
	while (d >= 0)
	{
		bit = 0;
		ft_printf("d: %d\n", d);
//		if (d % 2 != 0)
//		{
			while (bit <= 9)
			{
				count = a->top - 1;
				while (count >= 0)
				{
					temp = a->items[a->top - 1] / divisor;
					if (temp % 10 == bit)
						push_to_b(a, b);
					else
						rotate_a(a);
					count--;
				}
				bit++;
			}
			while (b->top != 0)
				push_to_a(b, a);
			print_sequence(a);
			divisor *= 10;
			d--;
	}
	//	else
	//	{
	//		while (bit <= 9)
	//		{
	//			count = b->top - 1;
	//			while (count >= 0)
	//			{
	//				if ((b->items[b->top - 1] / 10) % 10 == bit)
	//					push_to_a(b, a);
	//				else
	//					rotate_b(b);
	//				count--;
	//			}
	//			bit++;
	//		}
	//		d--;
	//	}
}
