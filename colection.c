/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:12:53 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/02 15:01:08 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	colection(t_mlx *lib)
{
	char	player_pos;

	player_pos = lib->tab.tab[lib->player.y / 50] \
		[(lib->player.x / 50)];
	if (player_pos == 'C')
	{
		lib->tab.inventory += 1;
		lib->tab.tab[lib->player.y / 50] \
		[(lib->player.x / 50)] = '0';
	}
	if (lib->tab.inventory == lib->tab.colectable)
	{
		if (player_pos == 'E')
		{
			ft_printf("You Win. ");
			close_win(lib);
		}
	}
}
