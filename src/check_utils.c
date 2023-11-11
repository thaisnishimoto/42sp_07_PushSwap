/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:06:25 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/10 10:59:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top - 1)
	{
		if (a->items[i] > a->items[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	print_sequence(t_stack *stack)
{
	int	i;

	i = stack->top - 1;
	ft_printf("[top] ");
	while (i >= 0)
		ft_printf("%d ", stack->items[i--]);
	ft_printf("[bottom]");
	ft_printf("\n");

}

void	ft_free_matrix(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
