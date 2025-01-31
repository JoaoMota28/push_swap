/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:25 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:34:54 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate_gnl(t_stack **stack_a, t_stack **stack_b, char *l)
{
	freestack(stack_a);
	freestack(stack_b);
	free(l);
	terminate(1);
}

void	execute_instruction(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\n')
		sa(stack_a, 1);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\n')
		sb(stack_b, 1);
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\n')
		ss(stack_a, stack_b, 1);
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\n')
		pa(stack_a, stack_b, 1);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\n')
		pb(stack_a, stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\n')
		ra(stack_a, 1);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\n')
		rb(stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\n')
		rr(stack_a, stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra(stack_a, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rrb(stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr(stack_a, stack_b, 1);
	else
		terminate_gnl(stack_a, stack_b, l);
}

void	check_commands(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	tmp = NULL;
	while (line && *line != '\n' && *line != '\0')
	{
		tmp = line;
		execute_instruction(stack_a, stack_b, line);
		line = get_next_line(0);
		if (tmp)
			free(tmp);
	}
	if (*stack_b || !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc == 1)
		return (0);
	stack_a = parse_args(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		freestack(&stack_a);
		terminate(1);
	}
	line = get_next_line(0);
	if (!line && !is_sorted(&stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(&stack_a))
		write(1, "OK\n", 3);
	else
		check_commands(&stack_a, &stack_b, line);
	freestack(&stack_a);
	freestack(&stack_b);
	return (0);
}
