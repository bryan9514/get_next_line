


#include "get_next_line.h"


char *extract_line(char **content)
{
    char *line;
    char *newline_pos;
    char *new_content;
    size_t len;

    newline_pos = ft_strrchr(*content, '\n');
    if (newline_pos)
    {
        len = newline_pos - *content + 1;
        line = ft_substr(*content, 0, len); // Extraer línea completa
        new_content = ft_strdup(newline_pos + 1); // Guardar datos restantes
        free(*content);
        *content = new_content;
    }
    else
    {
        line = ft_strdup(*content);
        free(*content);
        *content = NULL;
    }
    return (line);
}

char *read_buf(int fd, char *content)
{
    int     nb_read;
    char    *buffer;
    char    *temp;

    if (!content)
        content = ft_strdup(""); // Inicializa content si es NULL
    while (!ft_strrchr(content, '\n')) // Salir si encuentras \n
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
            return (free(content), NULL);
        nb_read = read(fd, buffer, BUFFER_SIZE);
        if (nb_read < 0)
            return (free(content), free(buffer), NULL);
        if (nb_read == 0)
        {
            free(buffer);
            break;
        }
        buffer[nb_read] = '\0';
        temp = content;
        content = ft_strjoin(content, buffer);
        free(temp);
        free(buffer);
    }
    return (content);
}

char *get_next_line(int fd)
{
    static char *content = NULL;
    char    *gnl;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    content = read_buf(fd, content);
    if (!content || *content == '\0')
    {
        free(content);
        content = NULL;
        return (NULL);
    }
    gnl = extract_line(&content);
    return (gnl); // Devuelve una línea completa
}
