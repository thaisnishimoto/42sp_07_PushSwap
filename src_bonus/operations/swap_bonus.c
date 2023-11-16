/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:30:04 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 17:34:07 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_stack *a)
{
	ft_swap_top(a);
}

void	swap_b(t_stack *b)
{
	ft_swap_top(b);
}

void	swap_both(t_stack *a, t_stack *b)
{
	ft_swap_top(a);
	ft_swap_top(b);
}

void	ft_swap_top(t_stack *stack)
{
	int	i;

	if (stack->top <= 1)
		return ;
	i = stack->top - 1;
	ft_swap(&stack->items[i], &stack->items[i - 1]);
}
