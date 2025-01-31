/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:08:50 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 15:57:27 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_src(t_stack **stack, int content)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->content != content)
		tmp = tmp->next;
	return (tmp->index);
}

int	cost_dst(t_stack **stack, int cont)
{
	t_stack	*tmp;
	int		close;
	int		found_smaller;

	tmp = *stack;
	close = max_value(stack);
	found_smaller = 0;
	while (tmp != NULL)
	{
		if (tmp->content < cont)
		{
			if (!found_smaller || tmp->content > close)
			{
				close = tmp->content;
				found_smaller = 1;
			}
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp->content != close)
		tmp = tmp->next;
	return (tmp->index);
}

void	switch_case(t_stack *node, t_cost src, t_cost dst)
{
	if (src.cost <= (src.size / 2) && dst.cost <= (dst.size / 2))
	{
		node->a_cost = src.cost;
		node->b_cost = dst.cost;
		node->flag = 1;
	}
	else if (src.cost <= (src.size / 2) && dst.cost > (dst.size / 2))
	{
		node->a_cost = src.cost;
		node->b_cost = dst.size - dst.cost;
		node->flag = 2;
	}
	else if (src.cost > (src.size / 2) && dst.cost <= (dst.size / 2))
	{
		node->a_cost = src.size - src.cost;
		node->b_cost = dst.cost;
		node->flag = 3;
	}
	else if (src.cost > (src.size / 2) && dst.cost > (dst.size / 2))
	{
		node->a_cost = src.size - src.cost;
		node->b_cost = dst.size - dst.cost;
		node->flag = 4;
	}
}

void	update_cost(t_stack **stack_src, t_stack **stack_dst)
{
	t_cost	src;
	t_cost	dst;
	t_stack	*tmp;

	tmp = *stack_src;
	src.size = stack_len(stack_src);
	dst.size = stack_len(stack_dst);
	while (tmp != NULL)
	{
		src.cost = cost_src(stack_src, tmp->content);
		dst.cost = cost_dst(stack_dst, tmp->content);
		switch_case(tmp, src, dst);
		tmp = tmp->next;
	}
}
