/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:50:50 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/08/10 22:49:55 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_window(t_data *obj, int p)
{
	mlx_clear_window(obj->mlx_ptr, obj->mlx_win);
	mlx_destroy_window(obj->mlx_ptr, obj->mlx_win);
	free_ptr(obj->map);
	free(obj->mlx_ptr);
	exit(p);
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
				(obj->player)->y = y * 32;
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

void	images(t_data *obj)
{
	int	h;

	(obj->img)->img_back = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/back.xpm", &h, &h);
	(obj->img)->img_walls = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/wall.xpm", &h, &h);
	(obj->img)->img_gate = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/gate.xpm", &h, &h);
	(obj->img)->img_coin = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/coin.xpm", &h, &h);
	(obj->img)->img_open_gate = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/open_gate.xpm", &h, &h);
	(obj->img)->p = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/player.xpm", &((obj->player)->width),
			&((obj->player)->height));
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
	obj->player = &p;
	obj->col = ft_strlen(*(obj->map));
	init_ptr(obj);
	create_player(obj);
	images(obj);
	ft_putstr_fd("counter: ", 1);
	ft_putnbr_fd((obj->player)->counter, 1);
	ft_putchar_fd('\n', 1);
	mlx_hook(obj->mlx_win, 17, 0L, e, obj);
	mlx_loop_hook(obj->mlx_ptr, render_next_frame, obj);
	mlx_key_hook(obj->mlx_win, key_hook, obj);
	mlx_loop(obj->mlx_ptr);
}
