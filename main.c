/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:52:24 by minylee           #+#    #+#             */
/*   Updated: 2023/06/23 22:58:05 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *data)
{
	mlx_destroy_image(data->dp.mlx, data->imgs.player.img);
	mlx_destroy_image(data->dp.mlx, data->imgs.collet.img);
	mlx_destroy_image(data->dp.mlx, data->imgs.black.img);
	mlx_destroy_image(data->dp.mlx, data->imgs.obstacle.img);
	mlx_destroy_image(data->dp.mlx, data->imgs.exit.img);
	mlx_destroy_image(data->dp.mlx, data->imgs.ground.img);
	mlx_destroy_window(data->dp.mlx, data->dp.win);
	exit(0);
}

int	check_move(t_game *data, int x, int y)
{
	if (get_tile(&data->map, x, y) == '1')
		return (0);
	else if (get_tile(&data->map, x, y) == 'E')
	{
		if (data->map.c_cnt == 0)
		{
			set_textbox(&data->dp, &data->imgs, "congratulations!");
			data->is_game_end = 1;
		}
		else
			set_textbox(&data->dp, &data->imgs, "get more fish(es)");
	}
	else if (get_tile(&data->map, x, y) == 'C')
	{
		set_tile(&data->map, x, y, 'X');
		set_textbox(&data->dp, &data->imgs, "you get fish!");
		data->map.c_cnt -= 1;
	}
	else
		set_textbox(&data->dp, &data->imgs, "");
	data->player.x = x;
	data->player.y = y;
	return (1);
}

int	key_hook(int keycode, t_game *data)
{
	int			move_before;
	t_player	*player;

	player = &data->player;
	if (keycode == KEY_ESC)
		exit_game(data);
	if (data->is_game_end)
		return (0);
	move_before = data->player.walk;
	put_img(&data->dp, data->imgs.ground.img, player->x, player->y);
	if (get_tile(&data->map, player->x, player->y) == 'E')
		put_img(&data->dp, data->imgs.exit.img, player->x, player->y);
	if (keycode == KEY_UP)
		data->player.walk += check_move(data, player->x, player->y - 1);
	else if (keycode == KEY_LEFT)
		data->player.walk += check_move(data, player->x - 1, player->y);
	else if (keycode == KEY_DOWN)
		data->player.walk += check_move(data, player->x, player->y + 1);
	else if (keycode == KEY_RIGHT)
		data->player.walk += check_move(data, player->x + 1, player->y);
	put_img(&data->dp, data->imgs.player.img, player->x, player->y);
	if (move_before != data->player.walk)
		print_walk(data->player.walk);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_game	data;

	if (argc != 2)
		perror_exit("Wrong argument detected");
	is_ber(argv[1]);
	map_parser(&data.map, argv[1]);
	init_data(&data);
	init_graphic(&data.dp, &data.imgs, data.map.width, data.map.height);
	set_map(&data);
	mlx_hook(data.dp.win, 17, 0L, exit_game, &data);
	mlx_key_hook(data.dp.win, key_hook, &data);
	mlx_loop(data.dp.mlx);
}
