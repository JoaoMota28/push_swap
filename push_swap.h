/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:42:36 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/29 11:59:04 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				a_cost;
	int				b_cost;
	int				flag;
	struct s_stack	*next;
}	t_stack;

int		is_valid_arg(char *str);
int		check_dupes(int argc, char **argv);
int		validation(int argc, char **argv);
int		split_case(int *argc, char ***argv);
t_stack	*parse_args(int argc, char **argv);
void	terminate(int code);
t_stack	*stack_new(int number);
void	stack_append(t_stack **stack, t_stack *new);
int		stack_len(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	stack_add_front(t_stack **stack, t_stack *new);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	freestack(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_two(t_stack **stack);
void	update_index(t_stack **stack);
int		ft_abs(int	val);
int		ft_bigger(int val1, int val2);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	update_cost(t_stack **stack_src, t_stack **stack_dst);
void	rotate_stacks(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);
int		max_value(t_stack **stack);
int		min_value(t_stack **stack);
int		last_cont(t_stack **stack);

#endif
