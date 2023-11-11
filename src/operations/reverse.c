/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/07 15:47:58 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_a(t_stack *a)
{
	ft_reverse_stack(a);
	ft_printf("rra\n");
}

void	reverse_b(t_stack *b)
{
	ft_reverse_stack(b);
	ft_printf("rrb\n");
}

void	reverse_both(t_stack *a, t_stack *b)
{
	ft_reverse_stack(a);
	ft_reverse_stack(b);
	ft_printf("rrr\n");
}

void	ft_reverse_stack(t_stack *stack)
{
	int	i;

	if (stack->top <= 1)
		return ;
	i = 0;
	while (i < stack->top - 1)
	{
		ft_swap(&stack->items[i], &stack->items[i + 1]);
		i++;
	}
}

