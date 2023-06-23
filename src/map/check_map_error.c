/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:12:25 by minylee           #+#    #+#             */
/*   Updated: 2023/06/23 22:57:28 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_basic_errors(t_map *map)
{
	int	cur;
	int	line;

	map->width = -1;
	cur = 0;
	line = 0;
	while (map->map[cur] != 0)
	{
		if (map->map[cur] == '\n')
		{
			if (map->width == -1)
				map->width = cur;
			else if (cur != map->width * (line + 1) + line)
				perror_exit("Map must be rectangular.");
			line += 1;
		}
		else if (map->map[cur] != '0' && map->map[cur] != '1'
			&& map->map[cur] != 'E' && map->map[cur] != 'C'
			&& map->map[cur] != 'P')
			perror_exit("Map must be only use 0, 1, E, P, C");
		cur += 1;
	}
	if (cur != map->width * (line + 1) + line)
		perror_exit("Map must be rectangular.");
}

static void	check_epc(t_map *map)
{
	if (map->c_cnt < 1)
		perror_exit("Map must have more than one collection.");
	if (map->e_cnt != 1)
		perror_exit("Map must have one exit.");
	if (map->p_cnt != 1)
		perror_exit("Map must have one player.");
}

static void	check_wall(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		if (row == 0 || row == map->height - 1)
		{
			col = 0;
			while (col < map->width)
			{
				if (get_tile(map, col, row) != '1')
					perror_exit("The map must be closed by walls.");
				col += 1;
			}
		}
		else if (get_tile(map, 0, row) != '1'
			|| get_tile(map, map->width - 1, row) != '1')
			perror_exit("The map must be closed by walls.");
		row += 1;
	}
}

void	check_map_errors(t_map *map, t_player *player)
{
	check_epc(map);
	check_wall(map);
	check_vailed_path(map, player);
}
