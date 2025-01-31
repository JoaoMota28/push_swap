/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:46:41 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:19:12 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		content;

	tmp = *stack;
	content = tmp->content;
	stack_append(stack, stack_new(content));
	*stack = tmp->next;
	free(tmp);
}

void	ra(t_stack **stack_a, int flag)
{
	rotate(stack_a);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int flag)
{
	rotate(stack_b);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag == 0)
		write(1, "rr\n", 3);
}
