/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:08:30 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 17:47:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

void	init_ray(t_data *data, t_ray *ray)
{
	ray->pos.x = data->player.pos.x;
	ray->pos.y = data->player.pos.y;
	ray->dir.x = data->player.dir.x;
	ray->dir.y = data->player.dir.y;
	ray->grid.x = (int)ray->pos.x;
	ray->grid.y = (int)ray->pos.y;
}

void	set_ray_step(t_ray *ray)
{
	if (ray->dir.x < 0)
		ray->step.x = -1;
	else
		ray->step.x = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;
	else
		ray->step.y = 1;
}

void	set_ray_delta_dist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->dist.delta_x = 1e30;
	else
		ray->dist.delta_x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->dist.delta_y = 1e30;
	else
		ray->dist.delta_y = fabs(1 / ray->dir.y);
}

void	set_ray_side_dist(t_ray *ray)
{
	if (ray->dir.x < 0)
		ray->dist.side_x = (ray->pos.x - ray->grid.x) * ray->dist.delta_x;
	else
		ray->dist.side_x = (ray->grid.x + 1.0 - ray->pos.x) * ray->dist.delta_x;
	if (ray->dir.y < 0)
		ray->dist.side_y = (ray->pos.y - ray->grid.y) * ray->dist.delta_y;
	else
		ray->dist.side_y = (ray->grid.y + 1.0 - ray->pos.y) * ray->dist.delta_y;
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
