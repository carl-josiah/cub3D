/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:03:37 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 10:44:59 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

static void	compute_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0) // turn back to 0
		ray->perp_wall_dist = ray->dist.side_x - ray->dist.delta_x;
	else
		ray->perp_wall_dist = ray->dist.side_y - ray->dist.delta_y;
}

static void	dda_loop(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->dist.side_x < ray->dist.side_y)
		{
			ray->dist.side_x += ray->dist.delta_x;
			ray->grid.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->dist.side_y += ray->dist.delta_y;
			ray->grid.y += ray->step.y;
			ray->side = 1;
		}
		if (data->map.grid[ray->grid.y][ray->grid.x] == '1')
			ray->hit = 1;
	}
}

static void	draw_wall_column(t_data *data, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	while (draw_start <= draw_end)
	{
		pixel_put(&data->mlx.screen, x, draw_start, 0xFFFFFF);
		draw_start++;
	}
}

void	cast_ray(t_data *data, int x)
{
	t_ray	ray;

	init_ray(data, &ray);
	set_ray_step(&ray);
	set_ray_delta_dist(&ray);
	set_ray_side_dist(&ray);
	ray.hit = 0;
	dda_loop(data, &ray);
	compute_perp_wall_dist(&ray);
	draw_wall_column(data, &ray, x);
}
