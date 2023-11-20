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

#include "push_swap.h"

void	ft_swap(t_list *content, int stack)
{
	int	temp;

	temp = content->stack[stack][0];
	content->stack[stack][0] = content->stack[stack][1];
	content->stack[stack][1] = temp;
}

void	ft_push(t_list *content, int from)
{
	int	to;

	to = 1 - from;
	ft_rotate(content, to, DOWN);
	content->size[to]++;
	content->stack[to][content->size[to] - 1] = content->stack[to][0];
	content->stack[to][0] = content->stack[from][0];
	content->stack[from][0] = 0;
	ft_rotate(content, from, UP);
	content->size[from]--;
}

void	ft_rotate(t_list *content, int stack, int direction)
{
	int	tmp;
	int	i;

	if (direction == UP && content->size[stack] != 0)
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
	if (direction == DOWN && content->size[stack] != 0)
	{
		i = content->size[stack];
		if (content->size[stack] != 0)
			tmp = content->stack[stack][content->size[stack] - 1];
		while (i > 0)
		{
			content->stack[stack][i] = content->stack[stack][i - 1];
			i--;
		}
		content->stack[stack][0] = tmp;
	}
}

void	ft_rotate_manager(t_list *content)
{
	int	val_a;
	int	val_b;
	int	dir_a;
	int	dir_b;
	int	direction;

	val_a = content->stack[A][content->index_cheapest];
	val_b = content->stack[B][content->target];
	dir_a = content->direction[A];
	dir_b = content->direction[B];
	direction = DIFFERENT;
	if (dir_a == dir_b)
		direction = SAME;
	if (direction == SAME && dir_b != NONE)
	{
		while (content->stack[A][0] != val_a && content->stack[B][0] != val_b)
			ft_double_rotate(content, dir_a);
	}
	while (content->stack[A][0] != val_a || content->stack[B][0] != val_b)
	{
		if (content->stack[A][0] != val_a)
			(ft_rotate(content, A, dir_a), write_op(content, dir_a, A));
		if (content->stack[B][0] != val_b)
			(ft_rotate(content, B, dir_b), write_op(content, dir_b, B));
	}
}

void	ft_double_rotate(t_list *content, int direction)
{
	if (direction == UP)
	{
		(ft_rotate(content, A, UP), ft_rotate(content, B, UP));
		write_op(content, RR, 2);
	}
	else if (direction == DOWN)
	{
		(ft_rotate(content, A, DOWN), ft_rotate(content, B, DOWN));
		write_op(content, RRR, 2);
	}
}
