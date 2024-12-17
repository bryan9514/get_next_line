/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:36:01 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/17 17:49:36 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>

char	*read_buff(int fd, char *data)
{
	char	*buffer;
	int		nb_read;
	char	*tmp;

	nb_read = 1;
	if(data == NULL)
		data = ft_strdup("");
	while (nb_read > 0 && !ft_strrchr(data, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (free(data), data = NULL, free(buffer), buffer = NULL,NULL);
		nb_read = read(fd, buffer,BUFFER_SIZE);
		if (nb_read < 0)
			return (free(data), data = NULL, free(buffer), buffer = NULL,NULL);
		buffer[nb_read] = '\0';
		tmp = data;
		data = ft_strjoin(data, buffer);
		free(tmp);
		free(buffer);
	}
	return (data);
}

// int		find_newline_index(char *data)
// {
// 	int	i;

// 	if (!data)
// 		return (-1);
// 	while (data[i] != '\0')
// 	{
// 		if (data[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// char	*extract_line(char **data)
// {
// 	size_t	len;
// 	char	*newline_pos;
// 	char	*tmp;
// 	char	*line;

// 	newline_pos = ft_strrchr(*data, '\n');
//  	if (!newline_pos)
// 	{
// 		len = newline_pos - *data + 1;
// 		tmp = ft_substr(*data, 0 ,len);
// 		free(*data);
// 		*data = tmp;
// 	}
// 	else
// 	{
// 		line = ft_strdup(*data);
// 		free(*data);
// 		*data = NULL;
// 	}
// 	return (line);
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

char	*get_next_line(int fd)
{
	static char	*data;
	char	*gnl;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = read_buff(fd, data);
	if (!data || *data == '\0')
		return (free (data), NULL);
	gnl = extract_line(&data);
	return (gnl);
}

int	main(void)
{
	int	fd;
	int count;
	char*line;

	count = 1;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf ("Open Error\n");
		return (1);
	}
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, line);
		free(line);
		count++;
	}
	close(fd);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total_s;

	total_s = (nmemb * size);
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_s)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}


char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
