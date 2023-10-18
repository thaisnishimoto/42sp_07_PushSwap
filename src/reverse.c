/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/18 00:30:07 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_stack(t_stack *stack)
{
	int	pos;

	if (stack->size <= 1)
		return ;
	pos = stack->size - 1;
	while (pos > 0)
	{
		ft_swap(&stack->items[pos], &stack->items[pos - 1]);
		pos--;
	}
	stack->items[pos] = temp;
}

void	reverse_a(t_stack *a)
{
	ft_reverse_stack(a);
	ft_printf("ra\n");
}

void	reverse_b(t_stack *b)
{
	ft_reverse_stack(b);
	ft_printf("rb\n");
}

void	reverse_both(t_stack *b)
{
	ft_reverse_stack(a);
	ft_reverse_stack(b);
	ft_printf("rr\n");
}
