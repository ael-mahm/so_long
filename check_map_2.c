/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:49:42 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:49:44 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *str, int argc)
{
	char	*ptr;

	if (argc != 2)
	{
		write(2, "Error:\nparameter error!", 24);
		exit(1);
	}
	ptr = ft_strchr(str, '.');
	if (ptr)
	{
		if ((ft_strncmp(ptr, ".ber", 4)) || (*(ptr + 4) != 0))
		{
			write(2, "Error:\ncheck extension!", 24);
			exit(1);
		}
	}
	else
	{
		write(2, "Error:\ncheck extension!", 24);
		exit(1);
	}
}

char	**open_and_read(char *str)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**ptr;

	ptr = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 1;
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ptr = ft_readmap(ptr, i);
		if (!ptr)
			return (NULL);
		ptr[j] = line;
		i++;
		j++;
	}
	return (ptr);
}

char	**ft_readmap(char **ptr, int size)
{
	char	**tmp;

	tmp = ft_calloc((sizeof(char *)), size + 1);
	if (!tmp)
	{
		free_ptr(ptr);
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(tmp, ptr, size * sizeof(char *));
		free(ptr);
	}
	return (tmp);
}

void	free_ptr(char **ptr)
{
	size_t	j;

	if (!ptr)
		return ;
	j = 0;
	while (*(ptr + j))
	{
		free(*(ptr + j));
		j++;
	}
	free(ptr);
}

void	check_map(t_data *obj)
{
	if (!ft_isrectangle(obj->map))
	{
		free_ptr(obj->map);
		write(2, "Error:\nThe map must be rectangular!\n", 37);
		exit(1);
	}
	else if (!ft_checklines(obj->map))
	{
		free_ptr(obj->map);
		write(2, "Error:\ncheck length of lines!\n", 31);
		exit(1);
	}
	else if (!ft_checkwalls(obj))
	{
		free_ptr(obj->map);
		write(2, "Error:\nThe map must be closed/surrounded by walls!\n", 52);
		exit(1);
	}
	else if (!ft_check_two(obj))
	{
		free_ptr(obj->map);
		write(2, "Error:\nmap must contain at least 1 E, 1 C, and 1 P!\n", 53);
		exit(1);
	}
}
