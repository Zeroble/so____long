/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:46 by minylee           #+#    #+#             */
/*   Updated: 2023/05/31 08:43:30 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	set_collection(t_game *data, const int col, const int row)
{
	put_img(&data->dp, data->imgs.collet.img, col, row);
	data->map.c_cnt += 1;
}

static void	set_player(t_game *data, const int col, const int row)
{
	put_img(&data->dp, data->imgs.player.img, col, row);
	data->map.p_cnt += 1;
	data->player.x = col;
	data->player.y = row;
}

static void	set_exit(t_game *data, const int col, const int row)
{
	data->map.e_cnt += 1;
	put_img(&data->dp, data->imgs.exit.img, col, row);
}

void	set_map(t_game *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map.height)
	{
		col = 0;
		while (col < data->map.width)
		{
			put_img(&data->dp, data->imgs.ground.img, col, row);
			if (get_tile(&data->map, col, row) == '1')
				put_img(&data->dp, data->imgs.obstacle.img, col, row);
			if (get_tile(&data->map, col, row) == 'C')
				set_collection(data, col, row);
			if (get_tile(&data->map, col, row) == 'E')
				set_exit(data, col, row);
			if (get_tile(&data->map, col, row) == 'P')
				set_player(data, col, row);
			col += 1;
		}
		row += 1;
	}
	check_map_errors(&data->map, &data->player);
}
