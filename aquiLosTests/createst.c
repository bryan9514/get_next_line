/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:43:01 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/04 17:43:06 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

//	Open a file descriptor for the "test.txt" file, in
//	truncated write only mode, and create the file if it doesn't
//	already exist. Read and write permissions for the owner, read
//	permissions for the group.
	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
//	Stop everything if the file could not be opened
	if (fd == -1)
		return (1);
//	Print the fd of the new file
	printf("fd = %d\n", fd);
//	Write into the file descriptor
	write(fd, "Hello World!\n", 13);
//	Close the file
	close(fd);
	return (0);
}
