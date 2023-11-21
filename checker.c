/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:15 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:17 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_operations(t_list *content, char *str)
{
	if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push(content, A);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push(content, B);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rotate(content, B, UP);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_rotate(content, A, UP);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_rotate(content, A, DOWN);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_rotate(content, B, DOWN);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		(ft_rotate(content, B, UP), ft_rotate(content, A, UP));
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		(ft_rotate(content, B, DOWN), ft_rotate(content, A, DOWN));
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_swap(content, A);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_swap(content, B);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		(ft_swap(content, B), ft_swap(content, A));
	else
		return (write(2, "ERROR\n", 6), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list		content;
	char		*str;

	if (argc < 2)
		return (0);
	if (error_check(argc, argv) < 0)
		return (write(2, "ERROR\n", 6), -1);
	if (init_struct(argc, argv, &content) == -1)
		return (write(2, "ERROR\n", 6), -1);
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (ft_operations(&content, str) == 0)
			return (free(str), -1);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (in_order(&content, A, LIMITED) == TRUE)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	((free(content.stack[0]), free(content.stack[1])), free(str));
	return (0);
}
