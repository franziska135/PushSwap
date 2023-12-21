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

#include "push_swap_bonus.h"

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
		return (write(2, "Error\n", 6), 0);
	return (1);
}

void	ft_free(t_list *content)
{
	if (content)
	{
		if (content->stack[0])
			(free(content->stack[0]), content->stack[0] = NULL);
		if (content->stack[1])
			(free(content->stack[1]), content->stack[1] = NULL);
		content = NULL;
	}
}

void	ft_free_gnl(t_gnl *gnl, int status)
{
	if (gnl)
	{
		if (gnl->new_string)
			(free(gnl->new_string), gnl->new_string = NULL);
		if (gnl->storage)
			(free(gnl->storage), gnl->storage = NULL);
		if (gnl->str)
			(free(gnl->str), gnl->str = NULL);
	}
	if (status == EXIT)
	{
		gnl = NULL;
		exit (1);
	}
}

void	ft_init_gnl(t_gnl *gnl)
{
	gnl->storage = NULL;
	gnl->str = NULL;
	gnl->new_string = NULL;
	gnl->gelesen = 1;
}

int	main(int argc, char *argv[])
{
	t_list		content;
	t_gnl		gnl;

	if (argc < 2)
		return (0);
	if (error_check(argc, argv) < 0)
		return (write(2, "Error\n", 6), -1);
	if (init_struct(argc, argv, &content) == -1)
		return (write(2, "Error\n", 6), -1);
	ft_init_gnl(&gnl);
	gnl.str = get_next_line(STDIN_FILENO, &gnl, &content);
	while (gnl.str)
	{
		if (ft_operations(&content, gnl.str) == 0)
			return (ft_free(&content), free(gnl.str), free(gnl.storage), 1);
		(free(gnl.str), gnl.gelesen = 1);
		gnl.str = get_next_line(STDIN_FILENO, &gnl, &content);
	}
	if (in_order(&content, A, FULL) == TRUE)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	(ft_free(&content), ft_free_gnl(&gnl, NEX));
	return (0);
}
