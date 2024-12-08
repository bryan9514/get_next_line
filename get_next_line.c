/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/08 14:57:58 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// char *read_buf(int fd, char *content)
// {
// 	int	nb_read;
// 	char	*buffer = NULL; // esta es la que tengo que darle a read  para guardar los datos
// 	char	*temp;

// 	nb_read = 1;
// 	if (content == NULL)
// 		content = ft_strdup("");
// 	while (nb_read > 0 )
// 	{
// 		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 		if (!buffer)
// 			return (free(content),NULL);
// 		nb_read = read(fd, buffer, BUFFER_SIZE);
// 		if (nb_read < 0)
// 			return (free (content),free (buffer),NULL);
// 		if (nb_read == 0)
//         {
//             free(buffer);
//             break;
//         }
//         buffer[nb_read] = '\0';
//         temp = content;
//         content = ft_strjoin(temp, buffer);
//         free(temp);
//         temp = NULL;
// 		if (ft_strrchr(buffer, '\n'))
// 			break ;

// 	}
// 	return (content);
// }

char *extract_line(char **content)
{
    char *line;
    char *newline_pos;
    char *new_content;
    size_t len;

    newline_pos = ft_strrchr(*content, '\n');
    if (newline_pos)
    {
        len = newline_pos - *content + 1;
        line = ft_substr(*content, 0, len); // Extraer línea completa
        new_content = ft_strdup(newline_pos + 1); // Guardar datos restantes
        free(*content);
        *content = new_content;
    }
    else
    {
        line = ft_strdup(*content);
        free(*content);
        *content = NULL;
    }
    return (line);
}

char *read_buf(int fd, char *content)
{
    int     nb_read;
    char    *buffer;
    char    *temp;

    nb_read = 1;
    if (!content)
        content = ft_strdup(""); // Inicializa content si es NULL
    while (nb_read > 0 && !ft_strrchr(content, '\n')) // Salir si encuentras \n
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
            return (free(content), NULL);
        nb_read = read(fd, buffer, BUFFER_SIZE);
        if (nb_read < 0)
            return (free(content), free(buffer), NULL);
        if (nb_read == 0)
        {
            free(buffer);
            break;
        }
        buffer[nb_read] = '\0';
        temp = content;
        content = ft_strjoin(content, buffer);
        free(temp);
        free(buffer);
    }
    return (content);
}
// char	*get_next_line(int fd)
// {
// 	static char	*content = NULL; //esta va contener todo lo que vamos a leer con otra variable


// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	content = read_buf(fd, content);

// 	return (content);
// }


char *get_next_line(int fd)
{
    static char *content = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    content = read_buf(fd, content);
    if (!content || *content == '\0')
    {
        free(content);
        content = NULL;
        return (NULL);
    }
    return (extract_line(&content)); // Devuelve una línea completa
}
