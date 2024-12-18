/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:46:22 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/19 15:51:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 1;
	fd = open("file.txt", O_RDONLY);
	if (fd <= 0)
		return (printf("Open Error"), 1);
	// line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d] - %s", count, line);
		free(line);
		count++;
	}
	close(fd);
}

// \e[36m%d : [\e[0m%s\e[36m]\e[0m \n
