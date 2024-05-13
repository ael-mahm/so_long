/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:02:29 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/18 11:09:24 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_counter(t_data *obj)
{
	char	*str;

	(obj->player)->counter++;
	str = ft_itoa((obj->player)->counter);
	createheader(obj);
	mlx_string_put(obj->mlx_ptr, obj->mlx_win,
		((obj->col) / 2) * 32, 4, 0xFFFFFF, str);
	free(str);
}

void	left(t_data *obj, int i, int j)
{
	if (*(*(obj->map + j) + i - 1) == 'C')
		*(*(obj->map + j) + i - 1) = '0';
	if (*(*(obj->map + j) + i - 1) == 'E' && !check_gate(obj))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (check_enemy(obj, -32, 0))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (*(*(obj->map + j) + i - 1) == 'E')
		return ;
	*(*(obj->map + j) + i) = '0';
	*(*(obj->map + j) + i - 1) = 'P';
	(obj->player)->x = (obj->player)->x - 32;
	print_counter(obj);
}

void	right(t_data *obj, int i, int j)
{
	if (*(*(obj->map + j) + i + 1) == 'C')
		*(*(obj->map + j) + i + 1) = '0';
	else if (*(*(obj->map + j) + i + 1) == 'E' && !check_gate(obj))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (check_enemy(obj, 32, 0))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (*(*(obj->map + j) + i + 1) == 'E')
		return ;
	*(*(obj->map + j) + i) = '0';
	*(*(obj->map + j) + i + 1) = 'P';
	(obj->player)->x = (obj->player)->x + 32;
	print_counter(obj);
}

void	down(t_data *obj, int i, int j)
{
	if (*(*(obj->map + j + 1) + i) == 'C')
		*(*(obj->map + j + 1) + i) = '0';
	else if (*(*(obj->map + j + 1) + i) == 'E' && !check_gate(obj))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (check_enemy(obj, 0, 32))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (*(*(obj->map + j + 1) + i) == 'E')
		return ;
	*(*(obj->map + j) + i) = '0';
	*(*(obj->map + j + 1) + i) = 'P';
	(obj->player)->y = (obj->player)->y + 32;
	print_counter(obj);
}

void	up(t_data *obj, int i, int j)
{
	if (*(*(obj->map + j - 1) + i) == 'C')
		*(*(obj->map + j - 1) + i) = '0';
	else if (*(*(obj->map + j - 1) + i) == 'E' && !check_gate(obj))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (check_enemy(obj, 0, -32))
	{
		print_counter(obj);
		exit_window(obj, 0);
	}
	else if (*(*(obj->map + j - 1) + i) == 'E')
		return ;
	*(*(obj->map + j) + i) = '0';
	*(*(obj->map + j - 1) + i) = 'P';
	(obj->player)->y = (obj->player)->y - 32;
	print_counter(obj);
}
