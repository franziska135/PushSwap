/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:15 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:17 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	just_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (i < argc)
	{
		if (ft_strlen_new(argv[i]) == 0)
			return (FALSE);
		while (argv[i][++j])
		{
			if (is_number(argv[i][j]) == FALSE && (argv[i][0] != '-')
					&& argv[i][0] != '+')
				return (FALSE);
			else if ((argv[i][0] == '-' && is_number(argv[i][1] == FALSE))
					|| (argv[i][0] == '-' && ft_strlen_new(argv[i]) < 2))
				return (FALSE);
			else if ((argv[i][0] == '+' && is_number(argv[i][1] == FALSE))
					|| (argv[i][0] == '+' && ft_strlen_new(argv[i]) < 2))
				return (FALSE);
		}
		j = -1;
		i++;
	}
	return (TRUE);
}

int	no_doublicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (i != j && ft_strncmp(argv[i], argv[j], 11) == 0)
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	just_int(int argc, char **argv)
{
	char	*number_str;
	int		i;

	i = 1;
	while (i < argc)
	{
		number_str = ft_itoa(ft_atoi(argv[i]));
		if (!number_str)
			return (FALSE);
		if (ft_strncmp(argv[i], number_str, 11) != 0)
			return (free(number_str), FALSE);
		i++;
		free(number_str);
	}
	return (1);
}

int	error_check(int argc, char **argv)
{
	if (just_digits(argc, argv) == FALSE)
		return (-1);
	if (no_doublicates(argc, argv) == FALSE)
		return (-2);
	if (just_int(argc, argv) == FALSE)
		return (-3);
	return (0);
}

int	init_struct(int argc, char **argv, t_list *content)
{
	int	i;

	i = 0;
	content->size[A] = 0;
	content->size[B] = 0;
	content->direction[A] = 0;
	content->direction[B] = 0;
	content->stack[A] = (int *)malloc(sizeof(int) * argc - 1);
	if (!content->stack[A])
		return (-1);
	content->stack[B] = (int *)malloc(sizeof(int) * argc - 1);
	if (!content->stack[B])
		return (free(content->stack[0]), -1);
	while (i < argc - 1)
	{
		content->stack[A][i] = ft_atoi(argv[i + 1]);
		content->size[A]++;
		i++;
	}
	content->total = content->size[A];
	return (0);
}
