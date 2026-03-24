/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:51:51 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:16:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <initialize.h>

void	init_tex(t_tex *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->f = -1;
	tex->c = -1;
	tex->mask = 0;
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->row = 0;
}

void	init_player(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

void	init_file(t_file *file)
{
	file->lines = NULL;
	file->line_count = 0;
	file->map_line = NULL;
}
