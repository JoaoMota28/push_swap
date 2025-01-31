/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:20:24 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int		tmp_content;
	t_stack	*tmp;

	if (stack_len(stack) < 2)
		return ;
	tmp = *stack;
	tmp_content = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = tmp_content;
}

void	sa(t_stack **stack, int flag)
{
	swap(stack);
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack, int flag)
{
	swap(stack);
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag == 0)
		write(1, "ss\n", 3);
}
