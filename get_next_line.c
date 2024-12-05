/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/05 18:46:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fill_line(int fd, char *buffer)
{
	size_t	nb_read;
	char	*line;

	buffer = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	if (!buffer)
	 	return (NULL);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read < 0)
		return (NULL);
	line[nb_read] = '\0';
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_line(fd, buffer);

	return (fill_line);
}
