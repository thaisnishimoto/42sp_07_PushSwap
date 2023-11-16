/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:16 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:37 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //read, write
# include <stdlib.h> //malloc, free, exit
# include "../libft/libft.h"

typedef struct s_stack
{
	int	maxsize;
	int	top;
	int	*items;
}	t_stack;

//Operations - sa, sb, ss
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_both(t_stack *a, t_stack *b);
void	ft_swap_top(t_stack *stack);

//Operations - pa, pb
void	push_to_a(t_stack *b, t_stack *a);
void	push_to_b(t_stack *a, t_stack *b);
void	ft_push_to_stack(t_stack *origin, t_stack *receiver);

//Operations - ra, rb, rr
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	ft_rotate_stack(t_stack *stack);

//Operations - rra, rrb, rrr
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	reverse_both(t_stack *a, t_stack *b);
void	ft_reverse_stack(t_stack *stack);

//Main function - Parse and check
char	**parse_argv(int argc, char *argv[]);
void	generate_stacks(t_stack *a, t_stack *b, char **n_matrix);
int		valid_atoi(const char *nptr, t_stack *a, t_stack *b, char **n_matrix);
void	check_for_duplicate(t_stack *a, t_stack *b);

//Sorting functions - Turk algorithm
void	ft_turk_sort(t_stack *a, t_stack *b);
void	push_cheapest_to_a(t_stack *b, t_stack *a, int num_pos);
int		ft_get_min_pos(t_stack *stack);
void	ft_opt_move_to_top_a(t_stack *a, int *num);
void	ft_opt_move_to_top_b(t_stack *b, int *num);

//Find cheapest - Turk utils
int		find_cheapest_num(t_stack *a, t_stack *b);
int		find_target_pos(t_stack *a, int num, t_stack *b);
int		*sort_cpy_stack(t_stack *a);
int		cost_to_target(t_stack *a, t_stack *b, int num_pos, int target_pos);
int		cost_to_top(t_stack *stack, int *num_pos);

//Sorting functions - Sort 3
void	ft_sort_3(t_stack *a);
int		ft_get_max_pos(t_stack *stack);

//Check and exit utils
int		check_if_sorted(t_stack *a);
void	ft_free_matrix(char **arrary, int size);
void	ft_handle_error(t_stack *a, t_stack *b, int stage, char **num_matrix);
void	print_sequence(t_stack *stack);

//Extra sorting algorithm and utilss
void	ft_opt_radixsort(t_stack *a, t_stack *b);
void	ft_quicksort(t_stack *a, t_stack *b);
void	ft_small_sort(t_stack *a, t_stack *b);
void	ft_radixsort(t_stack *a, t_stack *b, int base);
void	ft_simplify_nums(t_stack *a);
int		*sort_cpy(t_stack *a);

#endif
