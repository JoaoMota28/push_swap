/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:20:17 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/29 13:04:35 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_cost(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	min = INT_MAX;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->flag == 1 || tmp->flag == 4)
		{
			if (ft_bigger(tmp->a_cost, tmp->b_cost) < min)
				min = ft_bigger(tmp->a_cost, tmp->b_cost);
		}
		else
		{
			if ((tmp->a_cost + tmp->b_cost) < min)
				min = tmp->a_cost + tmp->b_cost;
		}
		tmp = tmp->next;
	}
	return min;
}

t_stack	*min_node(t_stack **stack_a)
{
	t_stack	*tmp;
	int		cost;

	tmp = *stack_a;
	cost = min_cost(stack_a);
	while (tmp != NULL)
	{
		if (tmp->flag == 1 || tmp->flag == 4)
		{
			if (ft_bigger(tmp->a_cost, tmp->b_cost) == cost)
				break ;
		}
		else
			if ((tmp->a_cost + tmp->b_cost) == cost)
				break ;
		tmp = tmp->next;
	}
	return tmp;
}

void	rotatestacks3(t_stack **st_a, t_stack **st_b, t_stack *tmp)
{
	if (tmp->flag == 4)
	{
		while (tmp->a_cost > 0 && tmp->b_cost > 0)
		{
			rrr(st_a, st_b);
			tmp->a_cost--;
			tmp->b_cost--;
		}
		while (tmp->a_cost-- > 0)
			rra(st_a);
		while (tmp->b_cost-- > 0)
			rrb(st_b);
	}
}

void	rotatestacks2(t_stack **st_a, t_stack **st_b, t_stack *tmp)
{
	if (tmp->flag == 2)
	{
		while (tmp->a_cost-- > 0)
			ra(st_a);
		while (tmp->b_cost-- > 0)
			rrb(st_b);
	}
	else if (tmp->flag == 3)
	{
		while (tmp->a_cost-- > 0)
			rra(st_a);
		while (tmp->b_cost-- > 0)
			rb(st_b);
	}
	else
		rotatestacks3(st_a, st_b, tmp);
}

void	rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = min_node(stack_a);
	if (tmp->flag == 1)
	{
		while (tmp->a_cost > 0 && tmp->b_cost > 0)
		{
			rr(stack_a, stack_b);
			tmp->a_cost--;
			tmp->b_cost--;
		}
		while (tmp->a_cost-- > 0)
			ra(stack_a);
		while (tmp->b_cost-- > 0)
			rb(stack_b);
	}
	else
		rotatestacks2(stack_a, stack_b, tmp);
}
