#ifndef GET
#define GET

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

// char    *get_next_line(int fd);
char	*read_buff(int fd, char *data);
void    *ft_calloc(size_t nmemb, size_t size);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
