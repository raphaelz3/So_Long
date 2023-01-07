/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:53:02 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/05 14:16:27 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_width(int fd, int height)
{
	char	*p;
	int		len;
	int		comp;

	p = get_next_line(fd);
	len = ft_strlen(p);
	while (height - 1 > 1)
	{
		p = get_next_line(fd);
		comp = ft_strlen(p);
		if (len != comp)
		{
			return (0);
		}
		height--;
	}
	free(p);
	close(fd);
	return (len - 1);
}

int	win_height(int fd)
{
	char	*p;
	int		height;

	height = 0;
	p = get_next_line(fd);
	while (p)
	{
		height++;
		free(p);
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	return (height);
}

void	init_tab(t_mlx *lib)
{
	lib->tab.player_count = 0;
	lib->tab.colectable = 0;
	lib->tab.exit_count = 0;
	lib->tab.height = 0;
	lib->tab.width = 0;
	lib->tab.control = 0;
	lib->tab.inventory = 0;
	lib->tab.steps = 0;
	lib->tab.floor_count = 0;
	lib->tab.initial_x = 1;
	lib->tab.initial_y = 1;
}
