/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:50:17 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:50:18 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_gate(t_data *obj)
{
	char	**str;
	int		i;
	int		j;

	str = obj->map;
	j = 0;
	i = 0;
	while (*(str + j))
	{
		i = 0;
		while (*(*(str + j) + i))
		{
			if (*(*(str + j) + i) == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_coins(t_data *obj)
{
	char	**str;
	int		i;
	int		j;
	int		c;

	str = obj->map;
	j = 0;
	i = 0;
	c = 1;
	while (*(str + j))
	{
		i = 0;
		while (*(*(str + j) + i))
		{
			if (*(*(str + j) + i) == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}
