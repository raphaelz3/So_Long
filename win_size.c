/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:53:02 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/11/03 17:55:24 by  rapgonca        ###   ########.fr       */
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

	p = malloc(sizeof(char));
	height = 0;
	while (p)
	{
		p = get_next_line(fd);
		height++;
	}
	free(p);
	close(fd);
	return (height - 1);
}
