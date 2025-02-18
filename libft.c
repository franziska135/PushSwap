/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:15 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:17 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (nbr * sign > 2147483647 || nbr * sign < -2147483648)
		return_exit(1);
	return (nbr * sign);
}

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (*s1 == '-')
	{
		s1++;
		s2++;
	}
	if (*s1 == '+')
		s1++;
	while (*s1 == '0')
		s1++;
	while (*s2 == '0')
		s2++;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (-1);
	else
		return (0);
}

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

char	*ft_itoa(int n)
{
	char		*converted;
	int			length;
	long int	number;

	length = ft_length(n);
	number = n;
	if (n < 0)
	{
		number = -number;
	}
	converted = (char *)malloc(sizeof(char) * (length + 1));
	if (converted == NULL)
		return (NULL);
	ft_write_str (converted, length, number, n);
	return (converted);
}
