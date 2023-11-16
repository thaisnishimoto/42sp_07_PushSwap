/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 22:05:15 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	rotate_both(t_stack *a, t_stack *b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
	ft_printf("rr\n");
}

void	ft_rotate_stack(t_stack *stack)
{
	int	i;

	if (stack->top <= 1)
		return ;
	i = stack->top - 1;
	while (i > 0)
	{
		ft_swap(&stack->items[i], &stack->items[i - 1]);
		i--;
	}
}
