/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 15:02:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**parse_argv(int argc, char *argv[])
{
	int		i;
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

void	generate_stacks(t_stack *a, t_stack *b, char **n_matrix)
{
	int	count;
	int	i;

	count = 0;
	while (n_matrix[count])
		count++;
	a->maxsize = count;
	a->top = count;
	a->items = ft_calloc(count + 1, sizeof(int));
	if (a->items == NULL)
		ft_handle_error(a, b, 0, n_matrix);
	b->maxsize = count;
	b->top = 0;
	b->items = ft_calloc(count + 1, sizeof(int));
	if (b->items == NULL)
		ft_handle_error(a, b, 1, n_matrix);
	i = 0;
	while (count > 0)
	{
		a->items[i] = valid_atoi(n_matrix[count - 1], a, b, n_matrix);
		i++;
		count--;
	}
	ft_free_matrix(n_matrix, i);
}

int	valid_atoi(const char *nptr, t_stack *a, t_stack *b, char **n_matrix)
{
	unsigned char	i;
	int				sign;
	long			num;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (nptr[i] == '\0')
		ft_handle_error(a, b, 2, n_matrix);
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	if (nptr[i] != '\0' && (nptr[i] < '0' || nptr[i] > '9'))
		ft_handle_error(a, b, 2, n_matrix);
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		ft_handle_error(a, b, 2, n_matrix);
	return (num);
}

void	check_for_duplicate(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top - 1)
	{
		j = i + 1;
		while (j < a->top)
		{
			if (a->items[i] != a->items[j])
				j++;
			else
				ft_handle_error(a, b, 3, NULL);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**num_matrix;

	if (argc < 2 || argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	num_matrix = parse_argv(argc, argv);
	generate_stacks(&a, &b, num_matrix);
	check_for_duplicate(&a, &b);
	if (check_if_sorted(&a) == 1)
		ft_turk_sort(&a, &b);
	free(a.items);
	free(b.items);
	return (0);
}
