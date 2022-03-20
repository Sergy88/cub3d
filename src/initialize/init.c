/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:27:40 by sergey            #+#    #+#             */
/*   Updated: 2022/03/17 21:04:22 by Sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "cub3d.h"

void set_img_null(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void init_data(t_dataset *set)
{
	int	i;

	set->ceiling_rgb[0] = -1;
	set->floor_rgb[0] = -1;
	set->rend->mlx = NULL;
	set->rend->win = NULL;
	set->path_north = NULL;
	set->path_west = NULL;
	set->path_south = NULL;
	set->path_east = NULL;
	set_img_null(&set->rend->east);
	set_img_null(&set->rend->west);
	set_img_null(&set->rend->north);
	set_img_null(&set->rend->south);
	set_img_null(&set->rend->main_img);
	i = 0;
	while (i < 256)
	{
		set->k[i] = tan((double)(i * (screen_height / 256)) / 650);
		i++;
	}
	set->rend->i = 0;
	set->game->map_width = 0;
	set->game->map_height = 0;
	set->game->map = NULL;
}

void game_init(t_game *game)
{
	game->hero_pos = get_pos(game);
}
