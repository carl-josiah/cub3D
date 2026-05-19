/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:43:57 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 17:47:35 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Free and destroy everything and terminate the program.
 *
 * @param data Contains all the structs to free.
 */
static void	close_game(t_data *data)
{
	free_all(data->file.lines, data);
	exit(EXIT_SUCCESS);
}

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	else if (keycode == W_KEY)
		data->input.keys[KEY_W] = 1;
	else if (keycode == A_KEY)
		data->input.keys[KEY_A] = 1;
	else if (keycode == S_KEY)
		data->input.keys[KEY_S] = 1;
	else if (keycode == D_KEY)
		data->input.keys[KEY_D] = 1;
	else if (keycode == LEFT_KEY)
		data->input.keys[KEY_LEFT] = 1;
	else if (keycode == RIGHT_KEY)
		data->input.keys[KEY_RIGHT] = 1;
	return (0);
}

int	on_key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->input.keys[KEY_W] = 0;
	else if (keycode == A_KEY)
		data->input.keys[KEY_A] = 0;
	else if (keycode == S_KEY)
		data->input.keys[KEY_S] = 0;
	else if (keycode == D_KEY)
		data->input.keys[KEY_D] = 0;
	else if (keycode == LEFT_KEY)
		data->input.keys[KEY_LEFT] = 0;
	else if (keycode == RIGHT_KEY)
		data->input.keys[KEY_RIGHT] = 0;
	return (0);
}

int	on_window_close(t_data *data)
{
	close_game(data);
	return (0);
}
