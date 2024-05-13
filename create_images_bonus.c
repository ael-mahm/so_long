/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:35:49 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:35:56 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	(obj->img)->anim_1 = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/player_2.xpm", &h, &h);
	(obj->img)->anim_2 = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/player_3.xpm", &h, &h);
	(obj->img)->anim_3 = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/player_4.xpm", &h, &h);
	(obj->img)->en_1 = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/en_1.xpm", &h, &h);
	(obj->img)->p = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/player.xpm", &(obj->player)->width,
			&(obj->player)->height);
}

void	enemy_anim(t_data *obj)
{
	int	h;

	(obj->img)->en_4 = mlx_xpm_file_to_image(obj->mlx_ptr,
			"images/en_4.xpm", &h, &h);
}
