/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/17 19:14:11 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

typedef struct s_stack
{
	int	maxsize;
	int	size;
	int	*items;
}	t_stack;

void	initialize_stacks(t_stack *a, t_stack *b, char *argv[])
{
	int	len;
	int	i;

	len = 0;
	while (argv[len])
		len++;
	a->maxsize = len;
	a->size = len;
	a->items = ft_calloc(len, sizeof(int));
	b->maxsize = len;
	b->size = 0;
	b->items = ft_calloc(len, sizeof(int));
	i = 0;
	while (i < len)
	{
		a[i] = ft_atoi(&argv[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int	i;

	initialize_stacks(&a, &b, argv);
	ft_selection_sort(&a, &b);
	i = 0;
	while (i < a.maxsize)
	{
		ft_printf("%d\n", a.items[i]);
		i++;
	}
	return (0);
}
