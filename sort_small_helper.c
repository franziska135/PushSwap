/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:14:35 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/20 11:14:36 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*checks if stack is in order, return 0 if no, 1 if yes*/
int	in_order(t_list *content, int stack, int scope)
{
	int	i;

	i = 0;
	while (i < content->size[stack] - 1)
	{
		if (content->stack[stack][i] < content->stack[stack][i + 1])
			i++;
		else
			return (FALSE);
	}
	if (scope == FULL)
	{
		if (content->size[A] != content->total)
			return (FALSE);
	}
	return (TRUE);
}

int	in_order_confused(t_list *content, int stack)
{
	int	max;
	int	i;
	int	j;

	max = content->stack[stack][ft_max_ind(content, stack)];
	i = ft_max_ind(content, stack);
	while (i < content->size[stack] - 1)
	{
		if (content->stack[stack][i] < content->stack[stack][i + 1])
			i++;
		else
			return (FALSE);
	}
	i = ft_max_ind(content, stack);
	j = 0;
	while (j < i && (content->stack[stack][i + 1] != max))
	{
		if (content->stack[stack][j] < content->stack[stack][j + 1])
			j++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	ft_max_ind(t_list *content, int stack)
{
	int	j;
	int	size_stack;
	int	max;

	j = 0;
	size_stack = content->size[stack] - 1;
	max = 0;
	while (j < size_stack)
	{
		if (content->stack[stack][max] < content->stack[stack][j + 1])
			max = j + 1;
		j++;
	}
	return (max);
}

int	ft_min_ind(t_list *content, int stack)
{
	int	j;
	int	size_stack;
	int	min;

	j = 0;
	size_stack = content->size[stack] - 1;
	min = 0;
	while (j < size_stack)
	{
		if (content->stack[stack][min] > content->stack[stack][j + 1])
			min = j + 1;
		j++;
	}
	return (min);
}

int	compare(int one, int two, int comparison)
{
	if (comparison == BIGGEST)
	{
		if (one >= two)
			return (one);
		else
			return (two);
	}
	else if (comparison == SMALLEST)
	{
		if (one <= two)
			return (one);
		else
			return (two);
	}
	else
		return (-1);
}
