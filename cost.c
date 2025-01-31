/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:08:50 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/30 14:29:55 by jomanuel         ###   ########.fr       */
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

void	switch_case(t_stack *node, int src_s, int dst_s, int src_c, int dst_c)
{
	if (src_c <= (src_s / 2) && dst_c <= (dst_s / 2))
	{
		node->a_cost = src_c;
		node->b_cost = dst_c;
		node->flag = 1;
	}
	else if (src_c <= (src_s / 2) && dst_c > (dst_s / 2))
	{
		node->a_cost = src_c;
		node->b_cost = dst_s - dst_c;
		node->flag = 2;
	}
	else if (src_c > (src_s / 2) && dst_c <= (dst_s / 2))
	{
		node->a_cost = src_s - src_c;
		node->b_cost = dst_c;
		node->flag = 3;
	}
	else if (src_c > (src_s / 2) && dst_c > (dst_s / 2))
	{
		node->a_cost = src_s - src_c;
		node->b_cost = dst_s - dst_c;
		node->flag = 4;
	}
}

void	update_cost(t_stack **stack_src, t_stack **stack_dst)
{
	int		src_size;
	int		dst_size;
	int		src_cost;
	int		dst_cost;
	t_stack	*tmp;

	tmp = *stack_src;
	src_size = stack_len(stack_src);
	dst_size = stack_len(stack_dst);
	while (tmp != NULL)
	{
		src_cost = cost_src(stack_src, tmp->content);
		dst_cost = cost_dst(stack_dst, tmp->content);
		switch_case(tmp, src_size, dst_size, src_cost, dst_cost);
		tmp = tmp->next;
	}
}
