
#include <unistd.h>    // Para read(), close(), etc.
#include <fcntl.h>     // Para open(), O_RDONLY, etc.
#include <stdlib.h>    // Para malloc(), free(), size_t, NULL, etc.
#include <stddef.h>    // Opcional si usas size_t directamente
#include <stdio.h>

char  *get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
