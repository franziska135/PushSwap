/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:38 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 12:29:40 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *content)
{
	if (content->stack[0])
		free(content->stack[0]);
	if (content->stack[1])
		free(content->stack[1]);
}

int	main(int argc, char *argv[])
{
	t_list		content;

	if (argc < 2)
		return (0);
	if (error_check(argc, argv) < 0)
		return (write(2, "ERROR\n", 6), -1);
	if (init_struct(argc, argv, &content) == -1)
		return (write(2, "ERROR\n", 6), -1);
	sort(&content);
	(free(content.stack[0]), free(content.stack[1]));
	return (0);
}
