/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:24:32 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/09 12:24:35 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd, t_gnl *gnl, t_list *content)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl->new_string = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!gnl->new_string)
		return (ft_free(content), ft_free_gnl(gnl, EXIT), NULL);
	while (ft_newline(gnl->storage) == 0 && gnl->gelesen != 0)
	{
		gnl->gelesen = read(fd, gnl->new_string, BUFFER_SIZE);
		if (gnl->gelesen == -1)
			return (ft_free(content), ft_free_gnl(gnl, EXIT), NULL);
		gnl->new_string[gnl->gelesen] = '\0';
		gnl->storage = ft_strjoin(gnl->storage, gnl->new_string, gnl, content);
		if (!gnl->storage)
			return (NULL);
	}
	(free(gnl->new_string), gnl->new_string = NULL);
	if (gnl->gelesen == 0)
		return (free(gnl->storage), gnl->storage = NULL, NULL);
	gnl->new_string = ft_storage_to_output(gnl->storage, gnl, content);
	if (!gnl->new_string)
		return (NULL);
	gnl->storage = ft_extract_remnant(gnl->storage, gnl, content);
	if (!gnl->storage)
		return (free(gnl->new_string), gnl->new_string = NULL, NULL);
	return (gnl->new_string);
}

char	*ft_storage_to_output(char *storage, t_gnl *gnl, t_list *content)
{
	int		i;
	char	*output;

	if (!storage || !storage[0])
		return (NULL);
	i = ft_strlen(storage, '\n');
	if (storage[i] == '\n')
		i++;
	output = (char *)malloc(1 + i * sizeof(char));
	if (!output)
		return (ft_free(content), ft_free_gnl(gnl, EXIT), NULL);
	i = ft_strcpy(output, storage, '\n', 0);
	if (storage[i] == '\n')
		output[i++] = '\n';
	output[i] = '\0';
	return (output);
}

char	*ft_extract_remnant(char *storage, t_gnl *gnl, t_list *content)
{
	char	*remnant;
	int		start;
	int		end;

	start = ft_strlen(storage, '\n');
	if (storage[start] == '\0')
		return (free(storage), storage = NULL, NULL);
	if (storage[start] == '\n')
		start++;
	end = ft_strlen(storage, '\0');
	remnant = (char *)malloc(1 + end - start);
	if (!remnant)
		return (ft_free(content), ft_free_gnl(gnl, EXIT), NULL);
	end = ft_strcpy(remnant, storage, '\0', start);
	remnant[end] = '\0';
	(free(storage), storage = NULL);
	return (remnant);
}
