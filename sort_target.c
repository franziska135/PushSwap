/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:38 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 12:29:40 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*finds the target position in STACK_A for push back*/
int	ft_target_index(t_list *content, int value)
{
	int	j;
	int	max;
	int	edge;

	j = -1;
	max = content->size[A] - 1;
	edge = 0;
	while (++j < max)
	{
		if (value > content->stack[A][j] && value < content->stack[A][j + 1])
			return (j + 1);
	}
	if (value < content->stack[A][0] && value > content->stack[A][max])
		return (0);
	if (value < content->stack[A][0] && value < content->stack[A][max])
		return (ft_min_ind(content, A));
	else if (value > content->stack[A][0] && value > content->stack[A][max])
	{
		edge = ft_max_ind(content, A);
		if (edge == max)
			return (ft_min_ind(content, A));
		else
			return (edge + 1);
	}
	return (100);
}

int	target_decending(t_list *content, int value)
{
	int	j;
	int	max;

	j = 0;
	max = content->size[B] - 1;
	if (value > content->stack[B][ft_max_ind(content, B)])
		return (ft_max_ind(content, B));
	if (value < content->stack[B][ft_min_ind(content, B)])
	{
		if (ft_min_ind(content, B) == max)
			return (0);
		else
			return (ft_min_ind(content, B) + 1);
	}
	while (j < max)
	{
		if (value < content->stack[B][j] && value > content->stack[B][j + 1])
			return (j + 1);
		j++;
	}
	if (value > content->stack[B][0] && value < content->stack[B][max])
		return (0);
	return (50);
}

void	rotate_cor_dir(t_list *content, int stack, int index)
{
	if (index <= content->size[stack] - index)
		(ft_rotate(content, stack, UP), write_op(content, UP, stack));
	else
		(ft_rotate(content, stack, DOWN), write_op(content, DOWN, stack));
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

void	write_op(t_list *content, int operation, int stack)
{
	if ((operation == RA || operation == UP) && stack == A)
		write(1, "ra\n", 3);
	else if ((operation == RRA || operation == DOWN) && stack == A)
		write(1, "rra\n", 4);
	else if ((operation == RB || operation == UP) && stack == B)
		write(1, "rb\n", 3);
	else if ((operation == RRB || operation == DOWN) && stack == B)
		write(1, "rrb\n", 4);
	else if (operation == RR && stack == 2)
		write (1, "rr\n", 3);
	else if (operation == RRR && stack == 2)
		write (1, "rrr\n", 4);
	else if (operation == PB)
		write (1, "pb\n", 3);
	else if (operation == PA)
		write (1, "pa\n", 3);
	else if (operation == SA)
		write (1, "sa\n", 3);
	content->moves++;
}
