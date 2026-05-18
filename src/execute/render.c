/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:02:12 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 18:53:05 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 *
 * @brief Fill the top and bottom portion of the screen.
 *
 * @param data Pass mlx and tex structures for pixel_put()
 */
static void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				pixel_put(&data->mlx.screen, x, y, data->tex.ceiling_color);
			else
				pixel_put(&data->mlx.screen, x, y, data->tex.floor_color);
			x++;
		}
		y++;
	}
}

void	render(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	draw_background(data);
	while (x < WIN_WIDTH)
	{
		cast_ray(data, x, &ray);
		x++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.screen.img,
		0, 0);
}
