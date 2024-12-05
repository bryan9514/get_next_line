/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:35 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/04 20:04:11 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];	// stores the characters read
	int	fd;		// file descriptor to read
	int	nb_read;	// stores read's return value
	int	count;		// counts the number of reads

//	Open the cat.txt file in read only mode
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	Initialize the count variables
	nb_read = -1;
	count = 0;
//	Loop as long as read does not return 0 (which would mean that
//	there is nothing more to read in the file)
	while (nb_read != 0)
	{
		// Read 100 characters with read from the
		// opened file descriptor
		nb_read = read(fd, buf, BUFFER_SIZE);
		// Stop everything if read encounters an error
		if (nb_read == -1)
		{
			printf("Read error!\n");
			return (1);
		}
		// Read does not add the terminating \0
		// We can use the number of read characters as the index
		// of the last character in the string
		buf[nb_read] = '\0';
		// Print the buffer contents after read
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
		count++;
	}
//	Close the opened file descriptor
	close(fd);
	return (0);
}
