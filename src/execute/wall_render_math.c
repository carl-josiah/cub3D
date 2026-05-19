/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_math.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:38:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 16:45:48 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

t_vec2i	get_draw_bounds(int line_height)
{
	t_vec2i	bounds;

	bounds.x = -line_height / 2 + WIN_HEIGHT / 2;
	bounds.y = line_height / 2 + WIN_HEIGHT / 2;
	return (bounds);
}

t_vec2i	get_clamped_bounds(t_vec2i raw_bounds)
{
	t_vec2i	bounds;

	bounds = raw_bounds;
	if (bounds.x < 0)
		bounds.x = 0;
	if (bounds.y >= WIN_HEIGHT)
		bounds.y = WIN_HEIGHT - 1;
	return (bounds);
}

double	get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->pos.y + ray->perp_wall_dist * ray->dir.y);
	return (ray->pos.x + ray->perp_wall_dist * ray->dir.x);
}
