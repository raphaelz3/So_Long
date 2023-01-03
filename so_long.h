/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:05:57 by  rapgonca         #+#    #+#             */
/*   Updated: 2023/01/02 14:54:02 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define CONTENTS	"01PCE"

typedef struct t_img
{
	void	*img;
	int		x;
	int		y;
}t_img;

typedef struct t_mtx
{
	char	**tab;
	int		height;
	int		width;
	int		colectable;
	int		inventory;
	int		steps;
	int		player_count;
	int		exit_count;
	int		floor_count;
	int		initial_x;
	int		initial_y;
	int		control;
}t_mtx;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	t_img	floor;
	t_img	wall;
	t_img	player;
	t_img	exit;
	t_img	colect;
	t_mtx	tab;
}t_mlx;

void	map_define(t_mlx *lib);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		win_height(int fd);
int		win_width(int fd, int height);
int		inputs_key(int key, t_mlx *lib);
int		close_win(t_mlx *lib);
int		map_validation(t_mlx *lib);
void	set_image_mov(int key, t_mlx *lib);
int		recreat_map(t_mlx *lib);
void	colection(t_mlx *lib);
int		path_validation(t_mlx *lib);
void	player_initial_pos(t_mlx *lib);
void	recreat_img(int x, int y, char chr, t_mlx *lib);

#endif
