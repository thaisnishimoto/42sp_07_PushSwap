/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 17:35:00 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_stack *a)
{
	ft_rotate_stack(a);
}

void	rotate_b(t_stack *b)
{
	ft_rotate_stack(b);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
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
