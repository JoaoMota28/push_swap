/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:20:17 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/26 19:58:06 by jomanuel         ###   ########.fr       */
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
		if (tmp->cost < min)
			min = tmp->cost;
		tmp = tmp->next;
	}
	return min;
}

void	rotatestacks3(t_stack **st_a, t_stack **st_b, t_stack *tmp, int cost)
{
	if (tmp->flag == 4)
	{
		while (tmp->times > 0 && (cost - tmp->times) > 0)
		{
			rrr(st_a, st_b);
			tmp->times--;
			cost -= 2;
		}
		while (tmp->times--)
		{
			rra(st_a);
			cost--;
		}
		while (cost--)
			rrb(st_b);
	}
}

void	rotatestacks2(t_stack **st_a, t_stack **st_b, t_stack *tmp, int cost)
{
	if (tmp->flag == 2)
	{
		while (tmp->times--)
		{
			ra(st_a);
			cost--;
		}
		while (cost--)
			rrb(st_b);
	}
	else if (tmp->flag == 3)
	{
		while (tmp->times--)
		{
			rra(st_a);
			cost--;
		}
		while (cost--)
			rb(st_b);
	}
	else
		rotatestacks3(st_a, st_b, tmp, cost);
}

void	rotate_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	t_stack	*tmp;

	cost = min_cost(stack_a);
	tmp = *stack_a;
	while (tmp->cost != cost)
		tmp = tmp->next;
	if (tmp->flag == 1)
	{
		while (tmp->times > 0 && (cost - tmp->times) > 0)
		{
			rr(stack_a, stack_b);
			tmp->times--;
			cost -= 2;
		}
		while (tmp->times--)
		{
			ra(stack_a);
			cost--;
		}
		while (cost--)
			rb(stack_b);
	}
	else
		rotatestacks2(stack_a, stack_b, tmp, cost);
}
