/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:32:55 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/02 15:37:08 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_error(void)
{
	write(1, "Your map does not have a valid path;\n", 37);
	return ;
}

void	player_initial_pos(t_mlx *lib)
{
	int		x;
	int		y;
	char	crt;

	y = 0;
	while (y < lib->tab.height)
	{
		x = 0;
		while (x < lib->tab.width)
		{
			crt = lib->tab.tab[y][x];
			if (crt == 'P')
			{
				lib->player.x = 50 * x;
				lib->player.y = 50 * y;
			}
			x++;
		}
		y++;
	}
}

void	map_define(t_mlx *lib)
{
	int	x;
	int	y;

	player_initial_pos(lib);
	if (path_validation(lib) == 0)
		path_error();
	else
	{
		lib->tab.inventory = 0;
		lib->tab.steps = 0;
		lib->mlx = mlx_init();
		lib->win = mlx_new_window(lib->mlx, lib->tab.width * 50, \
		lib->tab.height * 50, "so_long");
		lib->floor.img = mlx_xpm_file_to_image(lib->mlx, "img/fl.xpm", &x, &y);
		lib->wall.img = mlx_xpm_file_to_image(lib->mlx, "img/wa.xpm", &x, &y);
		lib->colect.img = mlx_xpm_file_to_image(lib->mlx, "img/co.xpm", &x, &y);
		lib->exit.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/chest_closed.xpm", &x, &y);
		lib->player.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/stand-down.xpm", &x, &y);
		mlx_key_hook(lib->win, inputs_key, lib);
		mlx_hook(lib->win, 17, 1L << 0, close_win, lib);
		mlx_expose_hook(lib->win, recreat_map, lib);
		mlx_loop(lib->mlx);
	}
}
