/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/31 16:15:06 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

char	**parse_argv(int argc, char *argv[])
{
	int	i;
	char	*num_str;
	char	*temp;
	char	**num_matrix;

	i = 1;
	num_str = ft_strdup(argv[i]);
	while (++i < argc)
	{
		temp = ft_strjoin(num_str, " ");
		free(num_str);
		num_str = ft_strjoin(temp, argv[i]);
		free(temp);
	}
	num_matrix = ft_split(num_str, ' ');
	free(num_str);
	return (num_matrix);
}

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
	if (nptr[i] != 0 && (nptr[i] < '0' || nptr[i] > '9'))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (sign * num);
}

void	generate_stacks(t_stack *a, t_stack *b, char **num_matrix)
{
	int	count;
	int	i;

	count = 0;
	while (num_matrix[count])
		count++;
	a->maxsize = count;
	a->top = count;
	a->items = ft_calloc(count + 1, sizeof(int));
	b->maxsize = count;
	b->top = 0;
	b->items = ft_calloc(count + 1, sizeof(int));
	i = 0;
	while (count > 0)
	{
		a->items[i] = ft_valid_atoi(num_matrix[count - 1]);
		i++;
		count--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**num_matrix;

//	ft_printf("argc = %d\n", argc);
	if (argc < 2)
		exit(EXIT_FAILURE);
	num_matrix = parse_argv(argc, argv);
	generate_stacks(&a, &b, num_matrix);
	//print_sequence(&a);
	ft_radix_sort(&a, &b, 16);
//	ft_bubble_sort(&a, &b);
//	print_sequence(&a);
//	ft_printf("max int: %d\n", INT_MAX);
	//check for duplicate
	return (0);
}
