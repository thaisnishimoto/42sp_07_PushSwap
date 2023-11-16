/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:40:40 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 20:04:45 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

char	**parse_argv(int argc, char *argv[])
{
	int		i;
	char	*num_str;
	char	*temp;
	char	**num_matrix;

	i = 1;
	num_str = ft_strdup(argv[i]);
	if (num_str == NULL)
		return (NULL);
	while (++i < argc)
	{
		temp = ft_strjoin(num_str, " ");
		free(num_str);
		if (temp == NULL)
			return (NULL);
		num_str = ft_strjoin(temp, argv[i]);
		free(temp);
		if (num_str == NULL)
			return (NULL);
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

void	exec_sorting_instructions(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = ft_get_next_line(0);
	while (operation != NULL)
	{
		exec_operation(operation, a, b);
		free(operation);
		operation = ft_get_next_line(0);
	}
	if (check_if_sorted(a) == 1 || b->top != 0)
	{
		free(a->items);
		free(b->items);
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**num_matrix;

	if (argc == 1)
		return (EXIT_FAILURE);
	if (argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	num_matrix = parse_argv(argc, argv);
	if (num_matrix == NULL)
		ft_handle_error(&a, &b, 0, NULL);
	generate_stacks(&a, &b, num_matrix);
	check_for_duplicate(&a, &b);
	exec_sorting_instructions(&a, &b);
	ft_printf("OK\n");
	free(a.items);
	free(b.items);
	return (0);
}
