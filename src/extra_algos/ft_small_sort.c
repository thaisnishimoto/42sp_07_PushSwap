/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:02:27 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 15:19:33 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	int	min_pos;

	while (a->top > 3)
	{
		min_pos = ft_get_min_pos(a);
		ft_opt_move_to_top_a(a, &min_pos);
		push_to_b(a, b);
	}
	if (a->top == 3)
		ft_sort_3(a);
	else if (a->top == 2)
		rotate_a(a);
	while (b->top != 0)
		push_to_a(b, a);
}
