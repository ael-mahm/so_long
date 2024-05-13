/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:53:34 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:53:36 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_counter(t_data *obj)
{
	(obj->player)->counter++;
	ft_putstr_fd("counter: ", 1);
	ft_putnbr_fd((obj->player)->counter, 1);
	ft_putchar_fd('\n', 1);
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
	else if (*(*(obj->map + j - 1) + i) == 'E')
		return ;
	*(*(obj->map + j) + i) = '0';
	*(*(obj->map + j - 1) + i) = 'P';
	(obj->player)->y = (obj->player)->y - 32;
	print_counter(obj);
}
