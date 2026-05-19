/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:35:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 17:44:42 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	move_player(data);
	render(data);
	return (0);
}

void	event_handlers(t_data *data)
{
	initialize_input_keys(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, on_key_press, data);
	mlx_hook(data->mlx.win, 3, 1L << 1, on_key_release, data);
	mlx_hook(data->mlx.win, 17, 0, on_window_close, data);
	mlx_loop_hook(data->mlx.ptr, game_loop, data);
}
