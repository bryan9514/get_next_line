/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:46:22 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/08 14:52:27 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Open error");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL) // Lee línea por línea
	{
		printf("[%d] - %s", count, line); // Imprime la línea
		free(line); // Libera la línea procesada
		count++;
	}

	if (close(fd) < 0) // Asegúrate de cerrar el archivo correctamente
	{
		perror("Close error");
		return (1);
	}
	return (0);
}
