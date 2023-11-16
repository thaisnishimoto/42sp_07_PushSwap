/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:37:50 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/11/16 20:10:06 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h> //read, write
# include <stdlib.h> //malloc, free, exit
# include <stdio.h> // stdin_fileno
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

//Checker functions
char	**parse_argv(int argc, char *argv[]);
void	generate_stacks(t_stack *a, t_stack *b, char **n_matrix);
void	check_for_duplicate(t_stack *a, t_stack *b);
void	exec_sorting_instructions(t_stack *a, t_stack *b);

//Checker utils
int		valid_atoi(const char *nptr, t_stack *a, t_stack *b, char **n_matrix);
void	exec_operation(char *operation, t_stack *a, t_stack *b);
int		check_if_sorted(t_stack *a);
void	ft_free_matrix(char **arrary, int size);
void	ft_handle_error(t_stack *a, t_stack *b, int stage, char **num_matrix);

#endif
