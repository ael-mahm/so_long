/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:47:17 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:47:21 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isrectangle(char	**map)
{
	size_t	w;
	size_t	h;

	w = ft_strlen(*map);
	h = 0;
	while (*(map + h))
		h++;
	if (h < 3)
		return (0);
	if (h != w)
		return (1);
	return (0);
}

int	ft_checklines(char **map)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(*map);
	i = 1;
	while (*(map + i))
	{
		if (len != ft_strlen(*(map + i)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkwalls(t_data *obj)
{
	int	i;
	int	j;
	int	w;

	w = ft_strlen(*(obj->map)) - 1;
	i = 0;
	while (*(obj->map + i))
	{
		j = 0;
		if (i == 0 || i == obj->row - 1)
		{
			while (*(*(obj->map + i) + j) && *(*(obj->map + i) + j) == '1')
				j++;
			if (*((*(obj->map + i)) + j) != 0)
				return (0);
		}
		else
			if (*(*(obj->map + i) + 0) != '1' || *(*(obj->map + i) + w) != '1')
				return (0);
		i++;
	}
	return (1);
}

void	count_element(t_data *obj, int i, int j, t_map *map_count)
{
	if (*(*(obj->map + i) + j) == 'E')
		map_count->e = map_count->e + 1;
	else if (*(*(obj->map + i) + j) == 'P')
		map_count->p = map_count->p + 1;
	else if (*(*(obj->map + i) + j) == 'C')
		map_count->c = map_count->c + 1;
	else if (*(*(obj->map + i) + j) != '0'
		&& *(*(obj->map + i) + j) != '1')
		map_count->a = map_count->a + 1;
}

int	ft_check_two(t_data *obj)
{
	t_map	map_count;
	int		i;
	int		j;

	map_count.e = 0;
	map_count.p = 0;
	map_count.c = 0;
	map_count.a = 0;
	i = 1;
	while (*(obj->map + i) && i <= (obj->row - 2))
	{
		j = 0;
		while (*(*(obj->map + i) + j))
		{
			count_element(obj, i, j, &map_count);
			j++;
		}
		i++;
	}
	if (map_count.c != 0 && map_count.e != 0
		&& map_count.p == 1 && map_count.a == 0)
		return (1);
	return (0);
}
