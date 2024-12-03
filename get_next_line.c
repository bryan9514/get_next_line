/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/03 20:21:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *fill_line(int fd, char *gnl, char *line)
{
	gnl = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!gnl)
		return (NULL);

	read(fd, gnl, line);
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*gnl; //estatic buffer
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_line(fd, gnl, line;

}
