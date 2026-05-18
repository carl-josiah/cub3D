/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:13:07 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 18:53:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief
 * Find wall start and wall end.
 * The purpose of this function is
 * to make sure that the wall is in
 * the middle of the floor
 * and ceiling.
 *
 * @param line_height To determine the bounds and how tall the wall is.
 *
 * @return t_vec2i Return the bounds.
 */
static t_vec2i	get_draw_bounds(int line_height)
{
	t_vec2i	bounds;

	bounds.x = -line_height / 2 + WIN_HEIGHT / 2;
	bounds.y = line_height / 2 + WIN_HEIGHT / 2;
	if (bounds.x < 0)
		bounds.x = 0;
	if (bounds.y >= WIN_HEIGHT)
		bounds.y = WIN_HEIGHT - 1;
	return (bounds);
}

/**
 * @brief Find the position of where the ray hit the wall.
 *
 * @param ray Gather ray data to determine the position.
 *
 * @return double Return the position.
 */
static double	get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->pos.y + ray->perp_wall_dist * ray->dir.y);
	return (ray->pos.x + ray->perp_wall_dist * ray->dir.x);
}

/**
 * @brief Pick which column (x-axis) of the wall image to use.
 *
 * @param ray To compare side and dir structs to determine the column.
 * @param tex To use texture width to determine the column.
 *
 * @return int To return the column of the wall texture to use.
 */
static int	get_tex_x(t_ray *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	wall_x = get_wall_x(ray);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

/**
 * @brief Pick which row of the wall image to use.
 *
 * @param y Current screen pixel.
 * @param draw_start Where the wall begins.
 * @param line_height To determine the height of the wall.
 * @param tex Using tex height to determine the texture row to use.
 *
 * @return int To return the row of the wall texture to use.
 */
static int	get_tex_y(int y, int draw_start, int line_height, t_img *tex)
{
	int	tex_y;

	tex_y = (y - draw_start) * tex->height / line_height;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (tex_y);
}

void	draw_wall_column(t_data *data, t_ray *ray, int x)
{
	t_img	*tex;
	int		line_height;
	t_vec2i	bounds;
	int		tex_x;
	int		y;

	if (ray->perp_wall_dist <= 0)
		return ;
	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (line_height <= 0)
		line_height = 1;
	bounds = get_draw_bounds(line_height);
	tex = get_wall_texture(data, ray);
	tex_x = get_tex_x(ray, tex);
	y = bounds.x;
	while (y <= bounds.y)
	{
		pixel_put(&data->mlx.screen, x, y, get_texture_color(tex, tex_x,
				get_tex_y(y, bounds.x, line_height, tex)));
		y++;
	}
}
