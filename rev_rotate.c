/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:27 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:18:41 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_len(stack) < 2)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, int flag)
{
	rev_rotate(stack_a);
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int flag)
{
	rev_rotate(stack_b);
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
