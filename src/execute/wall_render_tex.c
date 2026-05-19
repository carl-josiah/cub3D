/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:38:02 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 17:36:47 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	get_tex_x(t_ray *ray, t_img *tex)
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

int	get_tex_y(int y, int draw_start, int line_height, t_img *tex)
{
	int	tex_y;

	tex_y = (y - draw_start) * tex->height / line_height;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (tex_y);
}

void	draw_textured_line(t_data *data, t_ray *ray, int x, t_wall_draw *wall)
{
	int	y;
	int	color;
	int	tex_y;

	wall->tex.tex = get_wall_texture(data, ray);
	wall->tex.tex_x = get_tex_x(ray, wall->tex.tex);
	y = wall->bounds.x;
	while (y <= wall->bounds.y)
	{
		tex_y = get_tex_y(y, wall->raw_bounds.x, wall->line_height,
				wall->tex.tex);
		color = get_texture_color(wall->tex.tex, wall->tex.tex_x, tex_y);
		pixel_put(&data->mlx.screen, x, y, color);
		y++;
	}
}
