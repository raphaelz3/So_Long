/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:58:38 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/01 14:59:08 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**valid_x(int y, int x, char **copy_table, t_mlx *lib)
{
	if (copy_table[y][x + 1] != '1' && copy_table[y][x + 1] != '2' )
	{
		if (copy_table[y][x + 1] == 'C' || copy_table[y][x + 1] == 'E')
			lib->tab.control += 1;
		copy_table[y][x + 1] = '3';
	}
	if (copy_table[y][x - 1] != '1' && copy_table[y][x - 1] != '2' )
	{
		if (copy_table[y][x - 1] == 'C' || copy_table[y][x - 1] == 'E')
			lib->tab.control += 1;
		copy_table[y][x - 1] = '3';
	}
	copy_table[y][x] = '2';
	return (copy_table);
}

char	**valid_y(int y, int x, char **copy_table, t_mlx *lib)
{
	if (copy_table[y + 1][x] != '1' && copy_table[y + 1][x] != '2' )
	{
		if (copy_table[y + 1][x] == 'C' || copy_table[y + 1][x] == 'E')
			lib->tab.control += 1;
		copy_table[y + 1][x] = '3';
	}
	if (copy_table[y - 1][x] != '1' && copy_table[y - 1][x] != '2' )
	{
		if (copy_table[y - 1][x] == 'C' || copy_table[y - 1][x] == 'E')
			lib->tab.control += 1;
		copy_table[y - 1][x] = '3';
	}
	copy_table[y][x] = '2';
	return (copy_table);
}

int	valid(int y, int x, char **copy_table, t_mlx *lib)
{
	while (copy_table[y][x] != '1')
	{
		if (copy_table[y][x] == '3')
			copy_table[y][x] = '2';
		valid_x(y, x, copy_table, lib);
		valid_y(y, x, copy_table, lib);
		x++;
	}
	y = 1;
	while (y < lib->tab.height)
	{
		x = 1;
		while (x < lib->tab.width)
		{
			if (copy_table[y][x] == '3')
				valid(y, x, copy_table, lib);
			else
				x++;
		}
		y++;
	}
	if (y == lib->tab.height && lib->tab.control < lib->tab.colectable + 1)
		return (0);
	else
		return (1);
}

int	path_validation(t_mlx *lib)
{
	char	**copy_table;
	int		y;
	int		x;

	lib->tab.control = 0;
	copy_table = malloc(sizeof(char *) * lib->tab.height);
	y = 0;
	while (y < lib->tab.height)
	{
	copy_table[y] = malloc(sizeof(char) * lib->tab.width);
	y++;
	}
	y = 0;
	while (y < lib->tab.height)
	{
		x = 0;
		while (x < lib->tab.width)
		{
			copy_table[y][x] = lib->tab.tab[y][x];
			x++;
		}
		y++;
	}
	return (valid(lib->player.y / 50, lib->player.x / 50, copy_table, lib));
}
