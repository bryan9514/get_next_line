/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:45:00 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/04 20:41:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE 42
#define BUFFER_SIZE 42

#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char *fill_line(int fd, char *buffer, char *line);




#endif
