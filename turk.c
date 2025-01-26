/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:58:25 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/26 22:09:51 by jomanuel         ###   ########.fr       */
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

// push_a not working correctly yet

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	val;

	pa(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		val = last_cont(stack_a);
		if (val < (*stack_b)->content)
			pa(stack_a, stack_b);
		else if ((*stack_b)->content < min_value(stack_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}
