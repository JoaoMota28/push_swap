/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:42:26 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 18:10:53 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = parse_args(argc, argv);
	stack_b = NULL;
	len = stack_len(&stack_a);
	if (argc < 2 || len == 0)
		terminate(1);
	if (!is_sorted(&stack_a))
	{
		if (len == 1)
			;
		else if (len == 2)
			sort_two(&stack_a);
		else if (len == 3)
			sort_three(&stack_a);
		else
			turk_sort(&stack_a, &stack_b);
	}
	return (freestack(&stack_a), freestack(&stack_b), 0);
}

	//t_stack	*tmp_a;
	//t_stack	*tmp_b;
/*tmp_a = stack_a;
	tmp_b = stack_b;
	printf("Stack A:\n");
	while (tmp_a != NULL)
	{
		printf("%i\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("Stack B:\n");
	while (tmp_b != NULL)
	{
		printf("%i\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}*/