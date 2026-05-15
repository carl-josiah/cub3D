/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:02:12 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 10:37:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

void	render(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.screen.img,
		0, 0);
}
