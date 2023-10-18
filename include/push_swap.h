/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:16 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/10/17 23:48:34 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include <unistd.h> //read, write
# include <stdlib.h> //malloc, free, exit
# include "../libft/libft.h"

//Operations - ra, rb. rr
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *b);
void	ft_rotate_stack(t_stack *stack);

//Operations - rra, rrb. rrr
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	reverse_both(t_stack *b);
void	ft_reverse_stack(t_stack *stack);

#endif
