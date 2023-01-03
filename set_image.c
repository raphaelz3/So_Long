/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:37:20 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/02 15:48:50 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image_mov(int key, t_mlx *lib)
{
	int	x;
	int	y;

	if (key == 'a')
		lib->player.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/stand-left-lt.xpm", &x, &y);
	else if (key == 'd')
		lib->player.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/stand-right-lt.xpm", &x, &y);
	else if (key == 'w')
		lib->player.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/player_up_0.xpm", &x, &y);
	else if (key == 's')
		lib->player.img = mlx_xpm_file_to_image(lib->mlx, \
		"img/down-1.xpm", &x, &y);
}

void	recreat_img(int x, int y, char chr, t_mlx *lib)
{
	if (chr == '1')
		mlx_put_image_to_window(lib->mlx, lib->win, \
		lib->wall.img, (50 * x), (50 * y));
	else
		mlx_put_image_to_window(lib->mlx, lib->win, \
		lib->floor.img, (50 * x), (50 * y));
	if (chr == 'E')
		mlx_put_image_to_window(lib->mlx, lib->win, \
		lib->exit.img, (50 * x), (50 * y));
	else if (chr == 'C')
		mlx_put_image_to_window(lib->mlx, lib->win, \
		lib->colect.img, (50 * x), (50 * y));
}
