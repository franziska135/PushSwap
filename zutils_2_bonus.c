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

#include "push_swap_bonus.h"

int	ft_length(long int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_write_str(char *converted, int length, long int number, int n)
{
	converted[length] = '\0';
	while (length > 0)
	{
		converted[length - 1] = number % 10 + '0';
		number = number / 10;
		length--;
	}
	if (n < 0)
	{
		converted[0] = '-';
	}
	return (converted);
}

int	ft_strlen_new(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
