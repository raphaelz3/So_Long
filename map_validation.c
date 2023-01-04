/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:43:23 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/01 15:34:05 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(void)
{
	write(1, "map error\n", 10);
	return (0);
}

int	characters_validation(int x, int y, t_mlx *lib)
{
	int	c;

	c = 0;
	while (CONTENTS[c])
	{
		if (lib->tab.tab[x][y] == CONTENTS[c])
			c = 5;
		else if (lib->tab.tab[x][y] != CONTENTS[c])
		{
			c++;
			if (c == 5)
				return (0);
		}
	}
	return (1);
}

int	content_validation(t_mlx *lib)
{
	int	validation;
	int	x;
	int	y;

	x = 0;
	validation = 0;
	while (x != lib->tab.height)
	{
		y = 0;
		while (y != lib->tab.width)
		{
			validation = characters_validation(x, y, lib);
			if (validation == 0)
				return (map_error());
			y++;
		}
		x++;
	}
	return (validation);
}

int	map_validation(t_mlx *lib)
{
	int	n;

	n = 0;
	if (lib->tab.player_count != 1 || lib->tab.exit_count != 1 || \
	lib->tab.colectable < 1)
		return (map_error());
	while (n != lib->tab.width)
	{
		if (lib->tab.tab[0][n] != '1' || \
		lib->tab.tab[lib->tab.height - 1][n] != '1')
			return (map_error());
		n++;
	}
	n = 0;
	while (n != lib->tab.height)
	{
		if (lib->tab.tab[n][0] != '1' || \
		lib->tab.tab[n][lib->tab.width - 1] != '1')
			return (map_error());
		n++;
	}
	return (content_validation(lib));
}
