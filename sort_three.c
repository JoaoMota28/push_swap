/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:43:18 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:19:44 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content > tmp->next->content)
		ra(stack, 0);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*tmp;
	int		second;
	int		third;

	tmp = *stack_a;
	second = tmp->next->content;
	third = tmp->next->next->content;
	if (tmp->content < second && second > third && third > tmp->content)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (tmp->content > second && second < third && third > tmp->content)
		sa(stack_a, 0);
	else if (tmp->content < second && second > third && third < tmp->content)
		rra(stack_a, 0);
	else if (tmp->content > second && second < third && third < tmp->content)
		ra(stack_a, 0);
	else if (tmp->content > second && second > third && third < tmp->content)
	{
		ra(stack_a, 0);
		sa(stack_a, 0);
	}
}
