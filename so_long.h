/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:46:37 by ael-mahm          #+#    #+#             */
/*   Updated: 2022/06/22 23:46:43 by ael-mahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# define LEFT_KEY 0
# define DOWN_KEY 1
# define RIGHT_KEY 2
# define UP_KEY 13
# define ESC_KEY 53

typedef struct s_player
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		counter;
}	t_player;

typedef struct s_map
{
	int	c;
	int	e;
	int	p;
	int	a;
}	t_map;

typedef struct s_images
{
	void	*img_back;
	void	*img_walls;
	void	*img_gate;
	void	*img_coin;
	void	*img_open_gate;
	void	*p;
}	t_images;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			row;
	int			col;
	t_player	*player;
	t_images	*img;
}	t_data;

void	check_extension(char *str, int argc);
char	**open_and_read(char *str);
char	**ft_readmap(char **ptr, int size);
void	free_ptr(char **ptr);
void	check_map(t_data *obj);
int		ft_isrectangle(char **map);
int		ft_checklines(char **map);
int		ft_check_two(t_data *obj);
int		ft_checkwalls(t_data *obj);
void	create_window(t_data *obj);
char	*get_next_line(int fd);
char	*get_line(char **str, char *position);
char	*check(char	**str, char *buf, int fd, int	*size);
char	*ft_before(char *str, size_t size);
char	*ft_after(char const *str, unsigned int start);
void	free_ptr(char **ptr);
void	init_ptr(t_data *obj);
void	create_player(t_data *obj);
void	background_and_walls(t_data *obj);
void	images(t_data *obj);
int		check_gate(t_data *obj);
void	up(t_data *obj, int i, int j);
void	down(t_data *obj, int i, int j);
void	right(t_data *obj, int i, int j);
void	left(t_data *obj, int i, int j);
void	exit_window(t_data *obj, int p);
int		key_hook(int keycode, t_data *obj);
int		render_next_frame(t_data *obj);

#endif
