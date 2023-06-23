/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:53:39 by minylee           #+#    #+#             */
/*   Updated: 2023/05/30 18:54:57 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_data(t_game *data)
{
	data->map.e_cnt = 0;
	data->map.p_cnt = 0;
	data->map.c_cnt = 0;
	data->player.walk = 0;
	data->is_game_end = 0;
}

void	init_graphic(t_dp *dp, t_imgs *img, int width, int height)
{
	dp->mlx = mlx_init();
	dp->height = PIXEL_PER_TILE * height + TEXT_WINDOW_HEIGHT;
	dp->width = PIXEL_PER_TILE * width;
	dp->win = mlx_new_window(dp->mlx, dp->width, dp->height, "SO____LONG~~~~");
	img->ground.img = set_img(dp, &img->ground, "./img/ground64.xpm");
	img->player.img = set_img(dp, &img->player, "./img/knight64.xpm");
	img->exit.img = set_img(dp, &img->exit, "./img/cat64.xpm");
	img->collet.img = set_img(dp, &img->collet, "./img/fish64.xpm");
	img->obstacle.img = set_img(dp, &img->obstacle, "./img/tree64.xpm");
	img->black.img = set_img(dp, &img->black, "./img/black64.xpm");
	set_textbox(dp, img, "get all fishes");
}
