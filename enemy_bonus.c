/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:46:12 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/08/10 22:49:01 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_enemy(t_data *obj, int mx, int my)
{
	int	i;

	i = 0;
	while ((obj->enemy + i)->is_l == 1)
	{
		if ((((obj->player)->x + mx) == (obj->enemy + i)->x)
			&& (((obj->player)->y + my) == (obj->enemy + i)->y))
			return (1);
		i++;
	}
	return (0);
}

void	initialize_enemy(t_data *obj, int *t)
{
	int	num;
	int	k;

	num = rand() % (obj)->row;
	if (*(obj->map + num) && num != (obj)->row && num != 0)
	{
		k = 0;
		while (*(*(obj->map + num) + k))
		{
			k = rand() % (obj)->col;
			if (*(*(obj->map + num) + k) == '0')
			{
				(((obj)->enemy) + *t)->x = k * 32;
				(((obj)->enemy) + *t)->y = num * 32 + 30;
				(((obj)->enemy) + *t)->is_l = 1;
				*t = *t + 1;
				break ;
			}
			k++;
		}
	}
}

void	create_enemy(t_data *obj)
{
	int		number;
	int		i;
	int		t;

	enemy_anim(obj);
	obj->c = 10;
	number = check_coins(obj);
	(obj)->enemy = malloc(sizeof(t_enemy) * number + 1);
	if (!(obj)->enemy)
		return ;
	i = 0;
	t = 0;
	while (i < number)
	{
		(((obj)->enemy) + i)->is_l = 0;
		i++;
	}
	i = 0;
	while (i < number)
	{
		initialize_enemy(obj, &t);
		i++;
	}
}

void	put_enemy(t_data *obj)
{
	int	i;

	i = 0;
	if (!(obj->enemy))
		return ;
	while (((obj->enemy) + i)->is_l == 1)
	{
		if (obj->c > 0)
		{
			mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
				(obj->img)->en_1, ((obj->enemy) + i)->x, ((obj->enemy) + i)->y);
		}
		else if (obj->c <= 0)
		{
			mlx_put_image_to_window(obj->mlx_ptr, obj->mlx_win,
				(obj->img)->en_4, ((obj->enemy) + i)->x, ((obj->enemy) + i)->y);
		}
		i++;
	}
	obj->c--;
	if (obj->c == -10)
	{
		obj->c = 10;
	}
}
