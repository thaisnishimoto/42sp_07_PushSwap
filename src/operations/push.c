/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:30:04 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/15 22:05:00 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_a(t_stack *b, t_stack *a)
{
	ft_push_to_stack(b, a);
	ft_printf("pa\n");
}

void	push_to_b(t_stack *a, t_stack *b)
{
	ft_push_to_stack(a, b);
	ft_printf("pb\n");
}

void	ft_push_to_stack(t_stack *origin, t_stack *receiver)
{
	if (origin->top == 0)
		return ;
	receiver->items[receiver->top] = origin->items[origin->top - 1];
	receiver->top++;
	origin->top--;
}
