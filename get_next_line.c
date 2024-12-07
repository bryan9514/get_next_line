/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/07 15:19:33 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *read_buf(int fd, char *content)
{
	int	nb_read;
	char	*buffer; // esta es la que tengo que darle a read  para guardar los datos

	if (content == NULL)
		content = ft_strdup("");
	while (ft_strrchr(buffer, '\n') == NULL)
	{
			buffer = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
			if (!buffer)
				return (NULL);
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (nb_read < 0)
			{
				free (content);
				free (buffer);
				return (NULL);
			}
			content = ft_strjoin(buffer,content);
	}
	return (content);
}
char	*get_next_line(int fd)
{
	static char	*content = NULL; //esta va contener todo lo que vamos a leer con otra variable
	// char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = read_buf(fd, content);
	// line = search_line(buffer);

	return (content);
}
