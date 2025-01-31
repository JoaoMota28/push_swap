/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:58:25 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/30 15:50:33 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	n;

	i = 0;
	n = stack_len(stack_a);
	if (n < 5)
		pb(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	while (i < (n - 5))
	{
		update_index(stack_a);
		update_index(stack_b);
		update_cost(stack_a, stack_b);
		rotate_stacks(stack_a, stack_b);
		pb(stack_a, stack_b);
		i++;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		if ((*stack_b)->content > last_cont(stack_a))
			pa(stack_a, stack_b);
		else if ((*stack_b)->content < min_value(stack_a))
		{
			if ((*stack_a)->content == min_value(stack_a))
				pa(stack_a, stack_b);
			else
			{
				while ((*stack_a)->content != max_value(stack_a))
					rra(stack_a);
				ra(stack_a);
				pa(stack_a, stack_b);
			}
		}
		else
			rra(stack_a);
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		n;
	t_stack	*tmp;
	int		val;

	push_b(stack_a, stack_b);
	sort_three(stack_a);
	val = max_value(stack_b);
	n = stack_len(stack_b);
	update_index(stack_b);
	tmp = *stack_b;
	while (tmp->content != val)
	{
		update_index(stack_b);
		if (tmp->index > (n/2))
			rb(stack_b);
		else
			rrb(stack_b);
		tmp = *stack_b;
	}
	push_a(stack_a, stack_b);
	while (!is_sorted(stack_a))
		rra(stack_a);
}
