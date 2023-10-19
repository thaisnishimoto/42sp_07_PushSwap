/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/18 21:18:06 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	ft_valid_atoi(const char *nptr)
{
	unsigned char	i;
	int				sign;
	int				num;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}

void	generate_stacks(t_stack *a, t_stack *b, char **num_list)
{
	int	count;
	int	i;

	count = 0;
	while (num_list[count])
		count++;
	a->maxsize = count;
	a->top = count;
	a->items = ft_calloc(count, sizeof(int));
	b->maxsize = count;
	b->top = 0;
	b->items = ft_calloc(count, sizeof(int));
	i = count - 1;
	while (i >= 0)
	{
		a[i] = ft_valid_atoi(&argv[i]);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**num_list;

	if (argc != 2)
		exit(EXIT_FAILURE);
	num_list = ft_split(argv[1], ' ');
	generate_stacks(&a, &b, num_list);
	return (0);
}
