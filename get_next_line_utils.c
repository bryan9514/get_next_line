/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:45 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/05 18:41:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

