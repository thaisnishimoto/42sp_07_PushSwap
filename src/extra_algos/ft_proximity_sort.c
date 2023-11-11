/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proximity_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:44:47 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/09 15:44:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_proximity_sort(t_stack *a, t_stack *b)
{
	int	min;

	while (a->top != 0)
	{
		min = ft_get_min(a);
		ft_opt_move_to_top_a(a, min);
		push_to_b(a, b);
	}
	while (b->top != 0)
		push_to_a(b, a);
}
