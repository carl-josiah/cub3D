/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:23:23 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 10:33:40 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

void	launch_game(t_data *data)
{
	open_window(data);
	create_image(data);
	load_textures(data);
	event_handlers(data);
	render(data);
	mlx_loop(data->mlx.ptr);
}
