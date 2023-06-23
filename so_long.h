/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:04:16 by minylee           #+#    #+#             */
/*   Updated: 2023/06/23 22:57:59 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include "mlx.h"

# define MAX_WIDTH_TILE 38
# define MAX_HEIGHT_TILE 20
# define TEXT_WINDOW_HEIGHT 25
# define PIXEL_PER_TILE 64

# define KEY_ESC 53
# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_DOWN 1
# define KEY_RIGHT 2

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_imgs {
	t_img	player;
	t_img	ground;
	t_img	obstacle;
	t_img	exit;
	t_img	collet;
	t_img	black;
}	t_imgs;

typedef struct s_dp {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_dp;

typedef struct s_map {
	char	map[MAX_HEIGHT_TILE * MAX_WIDTH_TILE + MAX_HEIGHT_TILE];
	char	map_[MAX_HEIGHT_TILE * MAX_WIDTH_TILE + MAX_HEIGHT_TILE];
	int		e_cnt;
	int		p_cnt;
	int		c_cnt;
	int		width;
	int		height;
}	t_map;

typedef struct s_player {
	int		x;
	int		y;
	int		walk;
}	t_player;

typedef struct s_game {
	t_dp		dp;
	t_imgs		imgs;
	t_map		map;
	t_player	player;
	int			is_game_end;
}	t_game;

void	init_data(t_game *data);
void	init_graphic(t_dp *dp, t_imgs *img, int width, int height);
void	*set_img(t_dp *dp, t_img *img, char *path);
void	put_img(t_dp *dp, void *img, int x, int y);
void	set_textbox(t_dp *dp, t_imgs *img, char *str);
void	print_walk(int walk);
int		print_number(int number, char *obases, char obase);
int		map_parser(t_map *map, const char *path);
char	get_tile(t_map *map, int x, int y);
int		set_tile(t_map *map, int x, int y, char c);
void	set_map(t_game *data);
void	put_img(t_dp *dp, void *img, int x, int y);
void	perror_exit(char *str);
void	check_map_errors(t_map *map, t_player *player);
void	check_basic_errors(t_map *map);
int		ft_strlen(char *str);
int		ft_strcpy(char *from, char *to);
void	check_vailed_path(t_map *map, t_player *player);
void	is_ber(const char *path);

#endif
