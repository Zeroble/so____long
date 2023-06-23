/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:09:55 by minylee           #+#    #+#             */
/*   Updated: 2023/06/23 23:04:43 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_parser(t_map *map, const char *path)
{
	int		fd;
	char	oversized;
	int		is_oversized;
	int		size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_exit("Map file not exist");
	size = read(fd, &map->map,
			MAX_HEIGHT_TILE * MAX_WIDTH_TILE + MAX_HEIGHT_TILE - 1);
	if (size == 0)
		perror_exit("Map file is empty");
	map->map[size] = 0;
	is_oversized = read(fd, &oversized, 1);
	if (is_oversized >= 1)
		perror_exit("Map size must be 38*20 or less.");
	check_basic_errors(map);
	map->height = (size + 1) / (map->width + 1);
	if (map->height > MAX_HEIGHT_TILE || map->width > MAX_WIDTH_TILE)
		perror_exit("Map size must be 38*20 or less.");
	ft_strcpy(map->map, map->map_);
	return (1);
}

char	get_tile(t_map *map, int x, int y)
{
	if (y >= map->height || x >= map->width)
		return ('!');
	return (map->map[(map->width) * y + y + x]);
}

int	set_tile(t_map *map, int x, int y, char c)
{
	if (y >= map->height || x >= map->width)
		return (-1);
	map->map[(map->width) * y + y + x] = c;
	return (1);
}
