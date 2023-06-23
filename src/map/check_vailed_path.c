/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vailed_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:32:01 by minylee           #+#    #+#             */
/*   Updated: 2023/05/31 10:17:49 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	get_tile_(t_map *map, int x, int y)
{
	if (y >= map->height || x >= map->width)
		return ('!');
	return (map->map_[(map->width) * y + y + x]);
}

static int	set_tile_(t_map *map, int x, int y, char c)
{
	if (y >= map->height || x >= map->width)
		return (-1);
	map->map_[(map->width) * y + y + x] = c;
	return (1);
}

static int	check_tile_and_apply(t_map *map, int col, int row)
{
	char	tile;

	tile = get_tile_(map, col, row);
	if (tile == '0' || tile == 'E' || tile == 'C')
	{
		set_tile_(map, col, row, 'X');
		return (1);
	}
	else
		return (0);
}

static int	drop_water(t_map *map)
{
	int	row;
	int	col;
	int	flag;

	row = 0;
	flag = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (get_tile_(map, col, row) == 'X')
			{
				flag |= check_tile_and_apply(map, col + 1, row);
				flag |= check_tile_and_apply(map, col - 1, row);
				flag |= check_tile_and_apply(map, col, row + 1);
				flag |= check_tile_and_apply(map, col, row - 1);
			}
			col += 1;
		}
		row += 1;
	}
	return (flag);
}

void	check_vailed_path(t_map *map, t_player *player)
{
	int	cur;

	set_tile_(map, player->x, player->y, 'X');
	while (drop_water(map))
	{
	}
	cur = 0;
	while (map->map_[cur] != 0)
	{
		if (map->map_[cur] == 'E' || map->map_[cur] == 'C')
			perror_exit("Map has no vailed path.");
		cur += 1;
	}
}
