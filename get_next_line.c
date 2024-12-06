/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/06 17:56:18 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *line_found(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			
		}
	}
}

char *fill_line(int fd)
{
	size_t	nb_read;
	static char	*buffer;
	char	*line;

	buffer = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	if (!buffer)
	 	return (NULL);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read <= 0)
		return (free (buffer),NULL);
	line = line_found (buffer);
	return (buffer);
}
char	*get_next_line(int fd)
{
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = fill_line(fd);

	return (tmp);
}
