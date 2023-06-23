/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:55:50 by minylee           #+#    #+#             */
/*   Updated: 2023/05/30 18:56:19 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*set_img(t_dp *dp, t_img *img, char *path)
{
	return (mlx_xpm_file_to_image(dp->mlx, path, &img->width, &img->height));
}

void	put_img(t_dp *dp, void *img, int x, int y)
{
	mlx_put_image_to_window(dp->mlx, dp->win, img,
		x * PIXEL_PER_TILE, y * PIXEL_PER_TILE);
}

void	set_textbox(t_dp *dp, t_imgs *img, char *str)
{
	int	cnt_tile;

	cnt_tile = 0;
	while (cnt_tile * PIXEL_PER_TILE < dp->width)
	{
		mlx_put_image_to_window(dp->mlx, dp->win, img->black.img,
			cnt_tile * PIXEL_PER_TILE, dp->height - TEXT_WINDOW_HEIGHT);
		cnt_tile += 1;
	}
	mlx_string_put(dp->mlx, dp->win,
		5, dp->height - TEXT_WINDOW_HEIGHT / 2 + 3, 0xffffffff, str);
}
