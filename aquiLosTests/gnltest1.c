
#include "get_next_line.h"  // Para la declaración de get_next_line



void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total_s;

	total_s = (nmemb * size);
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_s)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char  *get_next_line(int fd)
{
  int  bytes_read;
  char *cup_buffer;

  cup_buffer = ft_calloc (3 + 1, sizeof(char));
  if (cup_buffer == NULL)
    return (NULL);
  bytes_read = read(fd, cup_buffer, 3);
  if (bytes_read <= 0)
    return (NULL);
  return (cup_buffer);
}
