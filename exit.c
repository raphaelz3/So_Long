/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:10:35 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/05 15:23:32 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_tab(char **my_matrix, t_mlx *lib)
{
	int	n;

	n = 0;
	while (n < lib->tab.height)
	{
		free(my_matrix[n]);
		n++;
	}
	free(my_matrix);
}

int	close_win(t_mlx *lib)
{
	mlx_loop_end(lib->mlx);
	mlx_clear_window(lib->mlx, lib->win);
	mlx_destroy_window(lib->mlx, lib->win);
	mlx_destroy_image(lib->mlx, lib->fl.img);
	mlx_destroy_image(lib->mlx, lib->wa.img);
	mlx_destroy_image(lib->mlx, lib->player.img);
	mlx_destroy_image(lib->mlx, lib->exit.img);
	mlx_destroy_image(lib->mlx, lib->co.img);
	clean_tab(lib->tab.tab, lib);
	mlx_destroy_display(lib->mlx);
	free(lib->mlx);
	ft_printf("steps: %d\n", lib->tab.steps);
	exit(0);
}
