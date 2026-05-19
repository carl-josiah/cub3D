/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:40:19 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 17:41:22 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	draw_wall_column(t_data *data, t_ray *ray, int x)
{
	t_wall_draw	wall;

	if (ray->perp_wall_dist <= 0)
		return ;
	wall.line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (wall.line_height < 1)
		wall.line_height = 1;
	wall.raw_bounds = get_draw_bounds(wall.line_height);
	wall.bounds = get_clamped_bounds(wall.raw_bounds);
	draw_textured_line(data, ray, x, &wall);
}
