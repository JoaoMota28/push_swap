/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:19 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/29 12:20:13 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = number;
	new->index = 0;
	new->a_cost = 0;
	new->b_cost = 0;
	new->flag = 0;
	new->next = NULL;
	return (new);
}

void	stack_append(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*newstack;

	newstack = new;
	newstack->next = *stack;
	*stack = newstack;
}

void	freestack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
}
