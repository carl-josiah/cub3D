/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:35:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 07:49:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

static void	close_game(t_data *data)
{
	free_and_destroy(data);
	exit(EXIT_SUCCESS);
}

static int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	return (0);
}

int	event_handlers(t_data *data)
{
	mlx_key_hook(data->mlx.win, handle_key_press, data);
	// mlx_hook(data->mlx.win, 17, 0, close_hook, data);
	return (0);
}
