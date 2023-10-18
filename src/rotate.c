/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/17 23:45:44 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_stack(t_stack *stack)
{
	int	pos;
	int	temp;

	if (stack->size <= 1)
		return ;
	pos = stack->maxsize - stack->size;
	temp = stack->items[pos];
	while (pos < stack->maxsize - 1)
	{
		stack->items[pos] = stack->items[pos + 1];
		pos++;
	}
	stack->items[pos] = temp;
}

void	rotate_a(t_stack *a)
{
	ft_rotate_stack(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	ft_rotate_stack(b);
	ft_printf("rb\n");
}

void	rotate_both(t_stack *b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
	ft_printf("rr\n");
}
