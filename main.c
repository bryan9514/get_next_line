/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:46:22 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/07 13:21:45 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int 	count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf ("Open error !\n");
		return (1);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	while (line)
	{
		printf("[%d] - %s \n", count,line);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (0);
}

// int main(void)
// {
//   int    fd;
//   char  *next_line;
//   int  count;

//   count = 0;
//   fd = open("file.txt", O_RDONLY);
//   while (1)
//   {
//     next_line = get_next_line(fd);
//     if (next_line == NULL)
//       break ;
//     count++;
//     printf("[%d]:%s\n", count, next_line);
//     next_line = NULL;
//   }
//   free(next_line);
//   close(fd);
//   return (0);
// }
