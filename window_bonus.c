/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:52:23 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/23 00:27:50 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	createheader(t_data *obj)
{
	int	x;
	int	y;

	y = 0;
	while (y < 30)
	{
		x = 0;
		while (x < (obj->col * 32))
		{
			mlx_pixel_put(obj->mlx_ptr, obj->mlx_win, x, y, 0x110a60);
			x++;
		}
		y++;
	}
	if ((obj->player)->counter == 0)
	{
		mlx_string_put(obj->mlx_ptr, obj->mlx_win,
			((obj->col) / 2) * 32, 4, 0xFFFFFF, "0");
	}
}

void	create_player(t_data *obj)
{
	int	x;
	int	y;

	y = 0;
	while (*(obj->map + y))
	{
		x = 0;
		while (*(*(obj->map + y) + x))
		{
			if (*(*(obj->map + y) + x) == 'P')
			{
				(obj->player)->x = x * 32;
				(obj->player)->y = y * 32 + 30;
				break ;
			}
			x++;
		}
		y++;
	}
	(obj->player)->width = 32;
	(obj->player)->height = 32;
	(obj->player)->counter = 0;
}

int	e(void *obj)
{
	exit_window(obj, 0);
	return (1);
}

void	create_window(t_data *obj)
{
	t_images	img;
	t_player	p;

	obj->img = &img;
	obj->count = 0;
	obj->player = &p;
	obj->col = ft_strlen(*(obj->map));
	init_ptr(obj);
	images(obj);
	create_player(obj);
	createheader(obj);
	create_enemy(obj);
	mlx_hook(obj->mlx_win, 17, 0L, e, obj);
	mlx_loop_hook(obj->mlx_ptr, render_next_frame, obj);
	mlx_key_hook(obj->mlx_win, key_hook, obj);
	mlx_loop(obj->mlx_ptr);
}

void	exit_window(t_data *obj, int p)
{
	mlx_clear_window(obj->mlx_ptr, obj->mlx_win);
	mlx_destroy_window(obj->mlx_ptr, obj->mlx_win);
	free_ptr(obj->map);
	free(obj->mlx_ptr);
	exit(p);
}
