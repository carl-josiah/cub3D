/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:10:30 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/02 19:19:25 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	init_tex(t_tex *tex)
{
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
	tex->f_color = -1;
	tex->c_color = -1;
}

static void	init_map(t_map *map)
{
	map->w = 0;
	map->h = 0;
	map->grid = NULL;
}

void	init_data(t_data *data)
{
	init_tex(&data->tex);
	init_map(&data->map);
}
