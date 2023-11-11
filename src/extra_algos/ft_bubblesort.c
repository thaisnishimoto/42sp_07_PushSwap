/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:53:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/31 14:49:47 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_bubble_sort(t_stack *a, t_stack *b)
{
	int	count;

	while (b->top < b->maxsize - 1)
	{
		count = a->top - 1;
		while (count > 0)
		{
			if (a->items[a->top - 1] < a->items[a->top - 2])
				swap_a(a);
			rotate_a(a);
			count--;
		}
		push_to_b(a, b);
	}
	while (b->top != 0)
		push_to_a(b, a);
}
