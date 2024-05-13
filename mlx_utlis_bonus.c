/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:51:54 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:52:01 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_data *obj)
{
	int	i;
	int	j;

	j = ((obj->player)->y - 30) / 32;
	i = (obj->player)->x / 32;
	if ((keycode == LEFT_KEY && (*(*(obj->map + j) + i - 1) != '1')))
		left(obj, i, j);
	else if (keycode == RIGHT_KEY && (*(*(obj->map + j) + i + 1) != '1'))
		right(obj, i, j);
	else if (keycode == UP_KEY && (*(*(obj->map + j - 1) + i) != '1'))
		up(obj, i, j);
	else if (keycode == DOWN_KEY && (*(*(obj->map + j + 1) + i) != '1'))
		down(obj, i, j);
	else if (keycode == ESC_KEY)
		exit_window(obj, 1);
	return (0);
}

void	animation_player(t_data *obj)
{
	mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
		(obj->img)->anim_3, (obj->player)->x, (obj->player)->y);
	obj->count = 0;
}

void	put_image(t_data *obj, int i, int j, char **str)
{
	mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
		(obj->img)->img_back, j * 32, (i * 32) + 30);
	if (*(*(str + i) + j) == 'E' && !check_gate(obj))
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->img_open_gate, j * 32, (i * 32) + 30);
	else if (*(*(str + i) + j) == 'E')
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->img_gate, j * 32, (i * 32) + 30);
	if (*(*(str + i) + j) == 'C')
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->img_coin, j * 32, (i * 32) + 30);
}

void	background_and_walls(t_data *obj)
{
	int		i;
	int		j;
	char	**str;

	str = obj->map;
	i = 0;
	while (*(str + i))
	{
		j = 0;
		while (*(*(str + i) + j))
		{
			if (*(*(str + i) + j) == '1')
				mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
					(obj->img)->img_walls, j * 32, (i * 32) + 30);
			else
				put_image(obj, i, j, str);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_data *obj)
{
	background_and_walls(obj);
	put_enemy(obj);
	if (obj->count <= 5)
	{
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->p, (obj->player)->x, (obj->player)->y);
		obj->count++;
	}
	else if (obj->count <= 10)
	{
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->anim_1, (obj->player)->x, (obj->player)->y);
		obj->count++;
	}
	else if (obj->count <= 20)
	{
		mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
			(obj->img)->anim_2, (obj->player)->x, (obj->player)->y);
		obj->count++;
	}
	else
		animation_player(obj);
	return (0);
}
