/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:13:59 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/01 15:30:12 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_aloc(t_mlx *lib)
{
	int		n;

	lib->tab.tab = malloc(sizeof(char *) * lib->tab.height);
	n = 0;
	while (n < lib->tab.height)
	{
		lib->tab.tab[n] = malloc(sizeof(char) * lib->tab.width);
		n++;
	}
}

void	matrix_container(int fd, t_mlx *lib)
{
	int		n;
	int		l;
	char	*buff;

	lib->tab.exit_count = 0;
	lib->tab.colectable = 0;
	l = 0;
	buff = malloc(sizeof(char) * lib->tab.width);
	while (l != lib->tab.height)
	{
		n = 0;
		buff = get_next_line(fd);
		while (n != lib->tab.width)
		{
			lib->tab.tab[l][n] = buff[n];
			if (buff[n] == 'C')
				lib->tab.colectable += 1;
			else if (buff[n] == 'P')
				lib->tab.player_count += 1;
			else if (buff[n] == 'E')
				lib->tab.exit_count += 1;
			n++;
		}
		l++;
	}
}

void	map_matrix(char *map, int fd)
{
	t_mlx	lib;

	lib.tab.player_count = 0;
	lib.tab.height = win_height(fd);
	fd = open(map, O_RDONLY);
	lib.tab.width = win_width(fd, lib.tab.height);
	fd = open(map, O_RDONLY);
	lib.tab.tab = malloc(sizeof(char *));
	if (lib.tab.height <= 2 || lib.tab.width <= 4 || \
	lib.tab.height == lib.tab.width)
	{
		close(fd);
		write(1, "map size error\n", 15);
		return ;
	}
	else
	{
		tab_aloc(&lib);
		matrix_container(fd, &lib);
		close(fd);
		if (map_validation(&lib) == 1)
			map_define(&lib);
		else
			return ;
	}
}

int	arguments_check(char *args)
{
	int	n;

	if (!ft_strrchr(args, '.'))
	{
		write(1, "check extension\n", 16);
		return (0);
	}
	else
	{
		n = ft_strncmp(ft_strrchr(args, '.'), ".ber", 5);
		if (n != 0 || ft_strlen(args) < 5)
		{
			write(1, "check argument\n", 16);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*my_map;

	if (argc != 2)
	{
		write(1, "check arguments\n", 16);
		return (0);
	}
	else if (arguments_check(argv[1]) == 0)
		return (0);
	my_map = (char *) malloc((sizeof(char) * 7) + ft_strlen(argv[1]));
	my_map = ft_strjoin("./maps/", argv[1]);
	fd = open(my_map, O_RDONLY);
	if (fd < 0)
		perror("map not found");
	else
		map_matrix(my_map, fd);
	free(my_map);
	close(fd);
	return (0);
}
