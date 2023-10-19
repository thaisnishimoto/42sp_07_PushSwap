/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/18 16:00:11 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//int	ft_find_min_pos(int *array)
//void	ft_rotate_stack(t_stack *stack)
//{
//	int	temp;
//	int	i;
//
//	temp = stack->items[0];
//	i = 0;
//	while (i < stack->maxsize - 1)
//	{
//		stack->items[i] = stack->items[i + 1];
//		i++;
//	}
//	stack->items[i] = temp;
//}
//
//void	ft_push_element(t_stack *origin, t_stack *recipient)
//{
////	if (origin->curr_size == 0)
////		ft_handle_error();
//	int	pos;
//
//	pos = recipient->maxsize - recipent->curr_size;
//	recipient->items[pos] = origin->items[0];
//	recipient->curr_size++;
//	origin->curr_size--;
//}
//
//
//int	ft_selection_sort(t_stack *a, t_stack *b)
//{
//	int	i;
//	int	j;
//	int	min_temp;
//	int	operations;
//
//	i = 0;
//	operations = 0;
//	min_temp = a->items[i];
//	while (i < a->maxsize - 1)
//	{
//		if (min_temp > a->items[i + 1])
//			min_temp = a->items[i];
//		i++;
//	}
//	while (a->items[0] != min_temp)
//	{
//		ft_rotate_stack(a);
//		ft_printf("ra\n");
//		operations++;
//	}
//	ft_push_element(&a, &b);
//		ft_swap(&a->items[i + 1], &a->item[i]);
//		ft_printf("sa\n");
//	}
//	
//}
