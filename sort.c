/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:38 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 12:29:40 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort(t_list *content)
{
	int	min_index;

	if (in_order(content, A, FULL) == FALSE)
	{
		if (content->size[A] <= 3 && content->size[1] == 0)
			ft_sort_three(content, A);
		else if (content->size[A] > 3 && content->size[0] <= 5)
			ft_sort_five(content);
		else if (content->size[A] > 5)
			custom_sort(content);
		// min_index = ft_min_ind(content, A);
		// while (in_order(content, A, FULL) == 0)
		// 	(rotate_cor_dir(content, A, min_index));
	}
	return ;
}

void	ft_sort_three(t_list *content, int stack)
{
	if (content->stack[stack][0] > content->stack[stack][1] &&
		content->stack[stack][0] > content->stack[stack][2])
		(ft_rotate(content, stack, UP), write_op(content, UP, A));
	else if (content->stack[stack][0] > content->stack[stack][1] &&
		content->stack[stack][0] < content->stack[stack][2])
		(ft_swap(content, stack), write_op(content, SA, A));
	else if (content->stack[stack][0] < content->stack[stack][1] &&
		content->stack[stack][2] < content->stack[stack][1])
		(ft_rotate(content, stack, DOWN), write_op(content, RRA, A));
	if (in_order(content, stack, LIMITED) == TRUE)
		return ;
	else
		ft_sort_three(content, stack);
}

void	ft_sort_five(t_list *content)
{
	int	target_index;
	int	value_target;

	target_index = 0;
	while (content->size[A] > 3 && in_order(content, A, LIMITED) == 0)
		(ft_push(content, A), write_op(content, PB, NONE));
	// if (content->size[A] == 3)
	// 	ft_sort_three(content, A);
	// while (content->size[B] != 0)
	// {
	// 	target_index = ft_target_index(content, content->stack[B][0]);
	// 	value_target = content->stack[A][target_index];
	// 	while (content->stack[A][0] != value_target)
	// 		(rotate_cor_dir(content, A, target_index));
	// 	if (content->stack[A][0] == value_target)
	// 		(ft_push(content, B), write_op(content, PA, NONE));
	// }
}

void	custom_sort(t_list *content)
{
	int	value_target;
	int	target_index;
	int i = 0;

	while (content->size[B] < 2)
		(ft_push(content, A), write_op(content, PB, A));
	while (i < 1)
	//while (content->size[A] > 3 && (in_order_confused(content, A) == FALSE))
	{
		find_cheapest(content);
		calculate_direction(content, content->index_cheapest, content->target);
		if (i == 0)
		{
			
			printf("cheapest\t index: %d\tvalue: %d\n", content->index_cheapest, content->stack[A][content->index_cheapest]);
			printf("target\t index: %d\tvalue: %d\n", content->target, content->stack[B][content->target]);
			printf("dir_A\t%d\n", content->direction[A]);
			printf("dir_B\t%d\n\n", content->direction[B]);
		}
		// ft_rotate_manager(content);
		// 	(ft_push(content, A), write_op(content, PB, NONE));
	}
	// if (content->size[A] == 3)
	// 	ft_sort_three(content, A);
	// while (content->size[B] > 0)
	// {
	// 	target_index = ft_target_index(content, content->stack[B][0]);
	// 	value_target = content->stack[A][target_index];
	// 	while (content->stack[A][0] != value_target)
	// 		(rotate_cor_dir(content, A, target_index));
	// 	if (content->stack[A][0] == value_target)
	// 		(ft_push(content, B), write_op(content, PA, NONE));
	// }
}
