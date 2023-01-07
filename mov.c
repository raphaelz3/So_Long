/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:43:13 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/05 14:16:33 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	intput_axis_x(int key, t_mlx *lib)
{
	set_image_mov(key, lib);
	if (key == 'a')
	{
		if (lib->tab.tab[lib->player.y / 50] \
		[(lib->player.x / 50) - 1] != '1')
		{
			lib->tab.steps += 1;
			return (50);
		}
	}
	else if (key == 'd')
	{
		if (lib->tab.tab [lib->player.y / 50] \
		[(lib->player.x / 50) + 1] != '1')
		{
			lib->tab.steps += 1;
			return (-50);
		}
	}
	return (0);
}

int	intput_axis_y(int key, t_mlx *lib)
{
	set_image_mov(key, lib);
	if (key == 'w')
	{
		if (lib->tab.tab[(lib->player.y / 50) - 1][lib->player.x / 50] != '1')
		{
			lib->tab.steps += 1;
			return (50);
		}
	}
	else
	{
		if (lib->tab.tab[(lib->player.y / 50) + 1][lib->player.x / 50] != '1')
		{
			lib->tab.steps += 1;
			return (-50);
		}
	}
	return (0);
}

int	recreat_map(t_mlx *lib)
{
	int	x;
	int	y;

	y = 0;
	while (y < lib->tab.height)
	{
		x = 0;
		while (x < lib->tab.width)
		{
			ft_printf("\rsteps: %d\r", lib->tab.steps);
			recreat_img(x, y, lib->tab.tab[y][x], lib);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(lib->mlx, lib->win, lib->player.img, \
	lib->player.x, lib->player.y);
	return (0);
}

int	inputs_key(int key, t_mlx *lib)
{
	if (key == 'a' || key == 'd')
		lib->player.x -= intput_axis_x(key, lib);
	else if (key == 's' || key == 'w')
		lib->player.y -= intput_axis_y(key, lib);
	else if (key == 65307)
		close_win(lib);
	colection(lib);
	mlx_clear_window(lib->mlx, lib->win);
	recreat_map(lib);
	return (0);
}
