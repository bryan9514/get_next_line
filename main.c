/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:46:22 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/17 16:59:56 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	int	fd;
	int	count;
	char *line;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd <= 0)
		return (printf ("Open Error"),1);
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, line);
		free(line);
		count++;
	}
	close(fd);
}
