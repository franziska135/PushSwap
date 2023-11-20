/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:12:19 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/20 11:12:20 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_list *content)
{
	int	ind_cheap;
	int	cheapest_cost;
	int	current_cost;
	int	index;

	index = 1;
	ind_cheap = 0;
	cheapest_cost = calculate_cost(content, 0);
	while (index < content->size[A])
	{
		current_cost = calculate_cost(content, index);
		if (compare(cheapest_cost, current_cost, SMALLEST) < cheapest_cost)
		{
			ind_cheap = index;
			cheapest_cost = current_cost;
		}
		index++;
	}
	content->index_cheapest = ind_cheap;
	content->target = target_decending(content, content->stack[A][ind_cheap]);
	content->cost = cheapest_cost;
	return ;
}

/*calculates the cost of pushing  from stack a to stack b position*/
int	calculate_cost(t_list *content, int index_a)
{
	int	move_down;
	int	move_up;
	int	target;

	target = target_decending(content, content->stack[A][index_a]);
	move_up = compare(index_a, target, BIGGEST);
	move_down = content->size[A] - index_a;
	move_down = compare(move_down, content->size[B] - target, BIGGEST);
	if (index_a <= target)
	{
		if (cost_a_smaller(content, index_a, move_down, move_up) != -1)
			return (cost_a_smaller(content, index_a, move_down, move_up));
	}
	else if (target < index_a)
	{
		if (cost_b_smaller(content, index_a, move_down, move_up) != -1)
			return (cost_b_smaller(content, index_a, move_down, move_up));
	}
	return (compare(move_down, move_up, SMALLEST));
}

int	cost_a_smaller(t_list *content, int index_a, int down, int up)
{
	int	index_b;

	index_b = target_decending(content, content->stack[A][index_a]);
	if (down <= up && down <= (index_a + (content->size[B] - index_b)))
		return (down);
	else if (index_a + (content->size[B] - index_b) <= down
		&& index_a + (content->size[B] - index_b) <= up)
		return (index_a + (content->size[B] - index_b));
	else if (up <= down && up <= index_a + (content->size[B] - index_b))
		return (up);
	else
		return (-1);
}

int	cost_b_smaller(t_list *content, int index_a, int down, int up)
{
	int	index_b;

	index_b = target_decending(content, content->stack[A][index_a]);
	if (down <= up && down <= (index_b + (content->size[A] - index_a)))
		return (down);
	else if (up <= down && up <= (index_b + (content->size[A] - index_a)))
		return (up);
	else if (index_b + (content->size[A] - index_a) <= down
		&& (index_b + (content->size[A] - index_a)) <= up)
		return (index_b + (content->size[A] - index_a));
	else
		return (-1);
}

/*returns the index of the target element in a custom stack*/
// int	calculate_cost(t_list *content, int index_a)
// {
// 	int	target_index;
// 	int	move_down;
// 	int	move_up;

// 	target_index = target_decending(content, 
// content->stack[STACK_A][index_a]);
// 	move_up = compare(index_a, target_index, BIGGEST);
// 	move_down = content->size[STACK_A] - index_a;
// 	move_down = compare(move_down, content->size[STACK_B] - 
// target_index, BIGGEST);
// 	// move_up = index_a;
// 	// move_down = content->size[STACK_A] - index_a;
// 	if (index_a <= target_index)
// 	{
// 		if (content->size[STACK_B] - target_index < target_index - 
// index_a)
// 			move_up += content->size[STACK_B] - target_index;
// 		else
// 			move_up = target_index;
// 	}
// 	else if (move_down < content->size[STACK_B] - target_index)
// 	{
// 		if (content->size[STACK_B] - target_index - 
// (content->size[STACK_A] - index_a) > target_index)
// 			move_down += target_index;
// 		else
// 			move_down = content->size[STACK_B] - target_index;
// 	}
// 	return (compare(move_up, move_down, SMALLEST));
// }