/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:40:40 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 20:03:34 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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

void	exec_operation(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_to_a(b, a);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_to_b(a, b);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		swap_both(a, b);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_a(a);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_b(b);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		reverse_both(a, b);
	else
		ft_handle_error(a, b, 3, NULL);
}

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

void	ft_handle_error(t_stack *a, t_stack *b, int stage, char **num_matrix)
{
	int	i;

	i = 0;
	if (num_matrix != NULL)
	{
		while (num_matrix[i])
			i++;
		ft_free_matrix(num_matrix, i);
	}
	if (stage >= 1)
	{
		free(a->items);
		if (stage >= 2)
			free(b->items);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
