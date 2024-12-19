/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/19 18:01:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, char *data)
{
	int		nb_buffer;
	char	*buffer_data;

	nb_buffer = 1;
	if (data == NULL)
		data = ft_strdup("");
	while (nb_buffer > 0 && !ft_strrchr(data, '\n'))
	{
		buffer_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer_data)
			return (free(data),free(buffer_data), NULL);
		nb_buffer = read(fd, buffer_data, BUFFER_SIZE);
		if (nb_buffer < 0)
            return (free(data), free(buffer_data), NULL);
        if (nb_buffer == 0)
        {
            free(buffer_data);
            break;
        }
		buffer_data[nb_buffer] = '\0';
		data = ft_strjoin(data, buffer_data);
		free(buffer_data);
	}
	buffer_data = NULL;
	return (data);
}

char	*extract_line(char **data)
{
	char	*line;
	char	*newline;
	size_t	len;
	size_t  i;

	len = 0;
	while (*data[len] != '\n')
	{
		if (*data[len] == '\n')
			line = ft_substr(*data, 0, len);
		len++;
	}
	i = 0;
	while (*data[i] != '\0')
		i++;
	newline = ft_substr(*data, len+1, i-1);
	free(*data);
	*data = newline;
	return (line);
}

// char *extract_line(char **data)
// {
//     char *line;
//     char *newline_position;
//     char *new_data;
//     size_t len;

//     newline_pos = ft_strrchr(*data, '\n');
//     if (newline_position)
//     {
//         len = newline_position - *content + 1;
//         line = ft_substr(*content, 0, len); // Extraer línea completa
//         new_content = ft_strdup(newline_pos + 1); // Guardar datos restantes
//         free(*content);
//         *content = new_content;
//     }
//     else
//     {
//         line = ft_strdup(*content);
//         free(*content);
//         *content = NULL;
//     }
//     return (line);
// }

char	*get_next_line(int fd)
{
	static char	*data = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	data = read_buff(fd, data);
	line = extract_line(&data);
	return (line);
}
