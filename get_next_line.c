/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/09 15:41:34 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *read_buf(int fd, char *content)
{
	int	nb_read;
	char	*buffer = NULL; // esta es la que tengo que darle a read  para guardar los datos
	char	*temp;

	nb_read = 1;
	if (content == NULL)
		content = ft_strdup("");
	while (nb_read > 0 )
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (free(content),NULL);
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free (content),free (buffer),NULL);
		if (nb_read == 0)
        {
            free(buffer);
            break;
        }
        buffer[nb_read] = '\0';
        temp = content;
        content = ft_strjoin(temp, buffer);
        free(temp);
        temp = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;

	}
	return (content);
}


char	*get_next_line(int fd)
{
	static char	*content = NULL; //esta va contener todo lo que vamos a leer con otra variable


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = read_buf(fd, content);

	return (content);
}



