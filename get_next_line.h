/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:45:00 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/08 15:01:12 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE
// #define GET_NEXT_LINE

// #ifndef BUFFER_SIZE
// #define BUFFER_SIZE 5
// #endif

// #include <unistd.h>    // Para read(), close(), etc.
// #include <fcntl.h>     // Para open(), O_RDONLY, etc.
// #include <stdlib.h>    // Para malloc(), free(), size_t, NULL, etc.
// #include <stddef.h>    // Opcional si uso size_t directamente
// #include <stdio.h>

// char	*get_next_line(int fd);
// char *read_buf(int fd, char *content);
// void	*ft_calloc(size_t nmemb, size_t size);
// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strrchr(const char *s, int c);

// #endif

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char    *get_next_line(int fd);
char    *read_buf(int fd, char *content);
void    *ft_calloc(size_t nmemb, size_t size);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strrchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
