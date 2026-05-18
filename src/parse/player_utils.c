/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:01:09 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 16:32:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	set_spawn_north(t_data *data)
{
	data->player.dir.x = 0;
	data->player.dir.y = -1;
	data->player.plane.x = 0.66;
	data->player.plane.y = 0;
}

void	set_spawn_south(t_data *data)
{
	data->player.dir.x = 0;
	data->player.dir.y = 1;
	data->player.plane.x = -0.66;
	data->player.plane.y = 0;
}

void	set_spawn_east(t_data *data)
{
	data->player.dir.x = 1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;
}

void	set_spawn_west(t_data *data)
{
	data->player.dir.x = -1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = -0.66;
}
