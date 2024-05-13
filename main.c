/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:53:14 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:53:16 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_ptr(t_data *obj)
{
	obj->mlx_ptr = mlx_init();
	if (!(obj->mlx_ptr))
	{
		write(2, "Error:\nerror in connection", 27);
		free_ptr(obj->map);
		exit(1);
	}
	obj->mlx_win = mlx_new_window(obj->mlx_ptr,
			obj->col * 32, (obj->row * 32), "./so_long");
	if (!(obj->mlx_win))
	{
		write(2, "Error:\nerror in creation of the window!", 40);
		free_ptr(obj->map);
		free(obj->mlx_ptr);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	obj;
	char	**map;
	int		h;

	check_extension(argv[1], argc);
	map = open_and_read(argv[1]);
	if (!map)
	{
		write(2, "Error\nmap not found!\n", 22);
		return (1);
	}
	h = 0;
	while (*(map + h))
		h++;
	obj.row = h;
	obj.map = map;
	check_map(&obj);
	create_window(&obj);
	return (0);
}
