/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:43:18 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/25 12:18:20 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = *stack_a;
	if (tmp->content > tmp->next->content)
		ra(stack_a);
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
		sa(stack_a);
		ra(stack_a);
	}
	else if (tmp->content > second && second < third && third > tmp->content)
		sa(stack_a);
	else if (tmp->content < second && second > third && third < tmp->content)
		rra(stack_a);
	else if (tmp->content > second && second < third && third < tmp->content)
		ra(stack_a);
	else if (tmp->content > second && second > third && third < tmp->content)
	{
		ra(stack_a);
		sa(stack_a);
	}
}
