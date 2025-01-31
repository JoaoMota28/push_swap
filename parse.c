/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:19:29 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/31 19:11:12 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_case(int *argc, char ***argv)
{
	char	**array;
	int		i;

	if (*argc == 2)
	{
		array = ft_split((*argv)[1], ' ');
		i = 0;
		while (array[i])
			i++;
		*argc = i;
		*argv = array;
		return (1);
	}
	else
	{
		*argc = *argc - 1;
		*argv = *argv + 1;
		return (0);
	}
}

int	is_valid_arg(char *str)
{
	int		i;
	int		sign;
	long	count;

	i = 0;
	sign = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-' && sign == 0)
			sign--;
		else if (str[i] == '+' && sign == 0)
			sign++;
		else if (str[i] >= '0' && str[i] <= '9')
			count = count * 10 + str[i] - '0';
		else
			return (0);
		if ((count > INT_MAX && sign != -1) || (count * sign) < INT_MIN)
			return (0);
		i++;
	}
	if ((count > INT_MAX && sign != -1) || (count * sign) < INT_MIN)
		return (0);
	return (1);
}

int	check_dupes(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validation(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		if (!is_valid_arg(argv[i]))
			return (0);
		i++;
	}
	if (!check_dupes(argc, argv))
		return (0);
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	int		i;
	int		number;
	t_stack	*stack_a;
	int		mode;

	i = 0;
	mode = split_case(&argc, &argv);
	if (!validation(argc, argv))
	{
		if (mode == 1)
			ft_freeall(argv);
		terminate(1);
	}
	stack_a = NULL;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if (mode == 1)
			free(argv[i]);
		i++;
		stack_append(&stack_a, stack_new(number));
	}
	if (mode == 1)
		free(argv);
	return (stack_a);
}
