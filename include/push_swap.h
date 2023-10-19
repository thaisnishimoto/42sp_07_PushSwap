/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:16 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/18 15:58:48 by tmina-ni         ###   ########.fr       */
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

#endif
