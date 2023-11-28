/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:11:11 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/20 11:11:12 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_direction(t_list *content)
{
	int	index_a;
	int	index_b;

	index_a = content->index_cheapest;
	index_b = content->target;
	if (index_a <= content->size[A] - index_a)
		content->direction[A] = UP;
	else if (index_a > content->size[A] - index_a)
		content->direction[A] = DOWN;
	else
		content->direction[A] = NONE;
	if (index_b <= content->size[B] - index_b)
		content->direction[B] = UP;
	else if (index_b > content->size[B] - index_b)
		content->direction[B] = DOWN;
	else
		content->direction[B] = NONE;
	if (index_a == 0)
		content->direction[A] = NONE;
	if (index_b == 0)
		content->direction[B] = NONE;
}

void	calculate_direction(t_list *content, int index_a, int index_b)
{
	int	down;


	down = content->size[A] - index_a;
	down = compare(down, content->size[B] - index_b, BIGGEST);
	if (index_a <= index_b)
		dir_a_smal(content, index_a, index_b);
	else if (index_b < index_a)
		dir_b_smal(content, index_a, index_b);
}

void	dir_a_smal(t_list *content, int ind_a, int ind_b)
{
	int	up;
	int	down;

	up = compare(ind_a, ind_b, BIGGEST);
	down = content->size[A] - ind_a;
	down = compare(down, content->size[B] - ind_b, BIGGEST);
	if (down < up && down < (ind_a + (content->size[B] - ind_b)))
		ft_store_direction(content, DOWN, DOWN);
	else if (ind_a + (content->size[B] - ind_b) < down
		&& ind_a + (content->size[B] - ind_b) < up)
		ft_store_direction(content, UP, DOWN);
	else if (up < down && up < ind_a + (content->size[B] - ind_b))
		ft_store_direction(content, UP, UP);
	else
		ft_find_direction(content);
}

void	dir_b_smal(t_list *content, int ind_a, int ind_b)
{
	int	up;
	int	down;

	up = compare(ind_a, ind_b, BIGGEST);
	down = content->size[A] - ind_a;
	down = compare(down, content->size[B] - ind_b, BIGGEST);
	if (down < up && down < (ind_b + (content->size[A] - ind_a)))
		ft_store_direction(content, DOWN, DOWN);
	else if (up < down && up < (ind_b + (content->size[A] - ind_a)))
		ft_store_direction(content, UP, UP);
	else if (ind_b + (content->size[A] - ind_a) < down
		&& (ind_b + (content->size[A] - ind_a)) < up)
		ft_store_direction(content, DOWN, UP);
	else
		ft_find_direction(content);
}

void	ft_store_direction(t_list *content, int stack_a, int stack_b)
{
	content->direction[A] = stack_a;
	content->direction[B] = stack_b;
	if (content->index_cheapest == 0)
		content->direction[A] = NONE;
	if (content->target == 0)
		content->direction[B] = NONE;
}
