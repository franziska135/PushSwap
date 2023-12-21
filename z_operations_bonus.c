/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:15 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:17 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_list *content, int stack)
{
	int	temp;

	if (content->stack[stack] != 0)
	{
		temp = content->stack[stack][0];
		content->stack[stack][0] = content->stack[stack][1];
		content->stack[stack][1] = temp;
	}
}

void	ft_push(t_list *content, int from)
{
	int	to;

	if (content->size[from] != 0)
	{
		to = 1 - from;
		ft_rotate(content, to, DOWN);
		content->size[to]++;
		content->stack[to][content->size[to] - 1] = content->stack[to][0];
		content->stack[to][0] = content->stack[from][0];
		content->stack[from][0] = 0;
		ft_rotate(content, from, UP);
		content->size[from]--;
	}
}

void	ft_rotate(t_list *content, int stack, int direction)
{
	int	tmp;
	int	i;

	if (direction == UP && content->size[stack] > 1)
	{
		i = 1;
		tmp = content->stack[stack][0];
		while (i < content->size[stack])
		{
			content->stack[stack][i - 1] = content->stack[stack][i];
			i++;
		}
		content->stack[stack][content->size[stack] - 1] = tmp;
	}
	if (direction == DOWN && content->size[stack] > 1)
	{
		i = content->size[stack] - 1;
		tmp = content->stack[stack][content->size[stack] - 1];
		while (i > 0)
		{
			content->stack[stack][i] = content->stack[stack][i - 1];
			i--;
		}
		content->stack[stack][0] = tmp;
	}
}

void	return_exit(int status)
{
	write (2, "Error\n", 6);
	exit(status);
}
