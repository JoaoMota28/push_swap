/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:27:01 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:17:58 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (stack_len(stack1) == 0)
		return ;
	tmp = *stack1;
	stack_add_front(stack2, stack_new(tmp->content));
	*stack1 = tmp->next;
	free(tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_b, stack_a);
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 0)
		write(1, "pb\n", 3);
}
