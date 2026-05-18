/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:46:22 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 17:11:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	valid_direction(t_map *map, int x, int y)
{
	if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
		|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
		return (1);
	return (0);
}

static void	set_player_pos(t_data *data, int x, int y)
{
	data->player.pos.x = x + 0.5;
	data->player.pos.y = y + 0.5;
}

static void	set_player_dir(t_data *data, char spawn)
{
	if (spawn == 'N')
		set_spawn_north(data);
	else if (spawn == 'S')
		set_spawn_south(data);
	else if (spawn == 'E')
		set_spawn_east(data);
	else if (spawn == 'W')
		set_spawn_west(data);
}

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.grid[y][x])
		{
			if (valid_direction(&data->map, x, y))
			{
				set_player_pos(data, x, y);
				set_player_dir(data, data->map.grid[y][x]);
				data->map.grid[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
