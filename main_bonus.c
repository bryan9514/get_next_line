/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:26:54 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/21 12:18:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line;
	int		fd1, fd2, fd3;
	int		count1, count2, count3;

	count1 = 1;
	count2 = 1;
	count3 = 1;
	fd1 = open("bonus_1.txt", O_RDONLY);
	fd2 = open("bonus_2.txt", O_RDONLY);
	fd3 = open("bonus_3.txt", O_RDONLY);
	if (!fd1 || !fd2 || !fd3)
		return (printf("Open Error"), 1);
	while (1)
	{
		if ((line = get_next_line(fd1)) != NULL)
		{
			printf("\e[36m[File 1 - Linea %d] : \e[35m%s\e[0m", count1, line);
			free(line);
			count1++;
		}
		if ((line = get_next_line(fd2)) != NULL)
		{
			printf("\e[36m[File 2 - Linea %d] : \e[32m%s\e[0m", count2, line);
			free(line);
			count2++;
		}
		if((line = get_next_line(fd3)) != NULL)
		{
			printf("\e[36m[File 3 - Linea %d] : \e[37m%s\e[0m", count3, line);
			free(line);
			count3++;
		}
		if(!line)
			break;
	}
	printf("\n");
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

// int	main(void)
// {
//     char	*line;
//     int		fd1, fd2, fd3;
//     int		count1 = 1, count2 = 1, count3 = 1;

//     // Abrir múltiples archivos
//     fd1 = open("bonus_1.txt", O_RDONLY);
//     fd2 = open("bonus_2.txt", O_RDONLY);
//     fd3 = open("bonus_3.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0)
//         return (printf("Open Error\n"), 1);

//     // Leer alternando entre los archivos
//     while (1)
//     {
//         // Leer del primer archivo
//         if ((line = get_next_line(fd1)) != NULL)
//         {
//             printf("\e[36m[File 1 - Line %d]: \e[32m%s\e[0m", count1, line);
//             free(line);
//             count1++;
//         }

//         // Leer del segundo archivo
//         if ((line = get_next_line(fd2)) != NULL)
//         {
//             printf("\e[36m[File 2 - Line %d]: \e[32m%s\e[0m", count2, line);
//             free(line);
//             count2++;
//         }

//         // Leer del tercer archivo
//         if ((line = get_next_line(fd3)) != NULL)
//         {
//             printf("\e[36m[File 3 - Line %d]: \e[32m%s\e[0m", count3, line);
//             free(line);
//             count3++;
//         }

//         // Salir del bucle si todos los archivos han terminado
//         if (!line)
//             break;
//     }

//     // Cerrar los archivos
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }
