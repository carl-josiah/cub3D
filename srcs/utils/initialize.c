/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:10:30 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/25 19:17:29 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	init_tex(t_tex *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->f = -1;
	tex->c = -1;
	tex->mask = 0;
}

static void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
}

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir = 0;
}

void	init_data(t_data *data)
{
	init_tex(&data->tex);
	init_map(&data->map);
	init_player(&data->player);
}
