/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:08:00 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 14:29:45 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	is_wall(t_data *data, double x, double y)
{
	int		grid_x;
	int		grid_y;
	char	cell;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_y < 0 || grid_y >= data->map.height)
		return (1);
	if (grid_x < 0 || grid_x >= data->map.width)
		return (1);
	cell = data->map.grid[grid_y][grid_x];
	if (cell == '1' || cell == '\0' || cell == ' ')
		return (1);
	return (0);
}

static void	try_move(t_data *data, double new_x, double new_y)
{
	if (!is_wall(data, new_x, data->player.pos.y))
		data->player.pos.x = new_x;
	if (!is_wall(data, data->player.pos.x, new_y))
		data->player.pos.y = new_y;
}

static void	rotate_player(t_player *player, double rot)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = player->dir.x;
	old_dir_y = player->dir.y;
	old_plane_x = player->plane.x;
	old_plane_y = player->plane.y;
	player->dir.x = old_dir_x * cos(rot) - old_dir_y * sin(rot);
	player->dir.y = old_dir_x * sin(rot) + old_dir_y * cos(rot);
	player->plane.x = old_plane_x * cos(rot) - old_plane_y * sin(rot);
	player->plane.y = old_plane_x * sin(rot) + old_plane_y * cos(rot);
}

void	initialize_input_keys(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < KEY_COUNT)
	{
		data->input.keys[i] = 0;
		i++;
	}
}

// make this readable
void	move_player(t_data *data)
{
	double	speed;
	double	rot;

	speed = MOVE_SPEED;
	rot = ROT_SPEED;
	if (data->input.keys[KEY_W])
		try_move(data, data->player.pos.x + data->player.dir.x * speed,
			data->player.pos.y + data->player.dir.y * speed);
	if (data->input.keys[KEY_S])
		try_move(data, data->player.pos.x - data->player.dir.x * speed,
			data->player.pos.y - data->player.dir.y * speed);
	if (data->input.keys[KEY_A])
		try_move(data, data->player.pos.x + data->player.dir.y * speed,
			data->player.pos.y - data->player.dir.x * speed);
	if (data->input.keys[KEY_D])
		try_move(data, data->player.pos.x - data->player.dir.y * speed,
			data->player.pos.y + data->player.dir.x * speed);
	if (data->input.keys[KEY_LEFT])
		rotate_player(&data->player, -rot);
	if (data->input.keys[KEY_RIGHT])
		rotate_player(&data->player, rot);
}
