/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:11:05 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/19 23:07:28 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_before(char	*str, size_t size)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	if (size > len)
		size = len;
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(ptr + i) = *(str + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_after(char const *s, unsigned int start)
{
	size_t	size;
	size_t	i;
	char	*substr;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (*(s + start + i) != '\0')
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

char	*get_line(char **str, char *position)
{
	char	*tmp;
	char	*line;

	line = ft_before(*str, (position - 1) - *str + 1);
	tmp = ft_after(*str, position - *str + 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*check(char	**str, char *buf, int fd, int	*size)
{
	char	*new_string;

	while (!ft_strchr(*str, '\n') && *size > 0)
	{
		*size = read(fd, buf, 100);
		if ((*size < 0) || (*size == 0 && **str == 0))
		{
			free(*str);
			*str = NULL;
			return (*str);
		}
		buf[*size] = '\0';
		new_string = ft_strjoin(*str, buf);
		free(*str);
		*str = new_string;
	}
	return (get_line(str, ft_strchr(*str, '\n')));
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;
	char		*buffer;
	int			size;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * 100 + 1);
	if (!buffer)
		return (NULL);
	if (!string)
		string = ft_strdup("");
	size = 1;
	line = check(&string, buffer, fd, &size);
	free(buffer);
	return (line);
}
