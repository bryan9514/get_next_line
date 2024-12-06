/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:45:00 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/06 17:18:38 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42

// #include <fcntl.h>
// #include <stdio.h>

#include <unistd.h>    // Para read(), close(), etc.
#include <fcntl.h>     // Para open(), O_RDONLY, etc.
#include <stdlib.h>    // Para malloc(), free(), size_t, NULL, etc.
#include <stddef.h>    // Opcional si usas size_t directamente
#include <stdio.h>

char	*get_next_line(int fd);
char *fill_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);




#endif
#endif
