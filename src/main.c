/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/20 18:53:19 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**join_args(int	argc, const char *argv[])
{
	int	i;
	char	**num_list;
	char	*temp;

	i = 1;
	temp = ft_strjoin(argv[i], " ");
	while (i < argc - 1)
	{
		num_list = ft_strjoin(temp, argv[i]);
		free(temp);
		temp = ft_strjoin(num_list, " ");
		free(num_list);
		i++;
	}
	temp[i] = NULL;
}

//int	ft_count_num(char *s, char c)
//{
//	int	index;
//	int	count;
//
//	index = 0;
//	count = 0;
//	while (s[index])
//	{
//		while (s[index] == c)
//			index++;
//		if (s[index] && s[index] != c)
//			count++;
//		while (s[index] && s[index] != c)
//			index++;
//	}
//	return (count);
//}
//
//char	**parse_argv(int argc, char *argv[])
//{
//	char	**num_list;
//	int	i;
//	int	count;
//
//	i = 1;
//	while (i < argc - 1)
//	{
//		if (ft_strchr(argv[i], ' ') == NULL)
//		{
//			num_list = ft_strdup(&argv[i]);
//			num_list++;
//			i++;
//		}
//		else
//		{
//			count = ft_count_num(argv[i], ' ');
//			num_list = ft_split(argv[i], ' ');
//			num_list += count;
//			i++;
//		}
//	}
//	return (num_list);
//}

//char	**ft_join_args(char **argv)
//{
//	char	*tmp;
//	char	*str;
//	char	**matrix;
//	int		i;
//
//	i = 1;
//	tmp = ft_strdup(" ");
//	while (argv[i])
//	{
//		str = ft_strjoin(tmp, argv[i]);
//		free(tmp);
//		tmp = ft_strjoin(str, " \0");
//		free(str);
//		i++;
//	}
//	matrix = ft_split(tmp, ' ');
//	free(tmp);
//	return (matrix);
//}


//char	**parse_argv(int argc, char *argv[])
//{
//	char	*temp;
//	char	*num_list;
//	int	i;
//	int	count_num;
//
//	num_list = argv[1];
//	i = 1;
//	while (i < argc - 1)
//	{
//		temp = ft_strjoin(argv[i] " ");
//		num_list = ft_strjoin(temp, argv[]);
//		free(temp);
//		
//		while (num_list[count_num])
//			count_num++;
//	}
//	ft_printf("joined args: %s\n", num_list);
////	else if (argc == 2)
////		num_list = ft_split(argv[1], ' ');
////	else if (argc > 2)
////		num_list = argv[1];
//}

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
	i = 0;
	while (count > 0)
	{
		a->items[i] = ft_valid_atoi(num_list[count - 1]);
		i++;
		count--;
	}
}

int	main(int argc, char *argv[])
{
//	t_stack	a;
//	t_stack	b;
	char	**num_list;

	ft_printf("argc = %d\n", argc);
	if (argc < 2)
		exit(EXIT_FAILURE);
	num_list = parse_argv(argc, argv);
//	else if (argc == 2)
//		num_list = ft_split(argv[1], ' ');
//	else if (argc > 2)
//		num_list = argv[1];
	int	i;
	i = 0;
	while (num_list[i])
		ft_printf("%s, ", num_list[i++]);
	ft_printf("\n");
//	generate_stacks(&a, &b, num_list);
	return (0);
}
