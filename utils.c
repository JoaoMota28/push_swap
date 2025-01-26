/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:19:30 by jomanuel          #+#    #+#             */
/*   Updated: 2025/01/26 09:27:11 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add to libft?
// correct original libft according to this one (the change)
// if update libft, remove abs from this header

int	ft_abs(int val)
{
	if (val >= 0)
		return (val);
	else
		return(-val);
}

int	ft_bigger(int val1, int val2)
{
	if (val1 > val2)
		return (val1);
	else
		return (val2);
}
