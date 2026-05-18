/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:03:37 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 18:51:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Compute the distance from the ray to the wall hit.
 *
 * @param ray Ray structure to update.
 */
static void	compute_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->dist.side_x - ray->dist.delta_x;
	else
		ray->perp_wall_dist = ray->dist.side_y - ray->dist.delta_y;
}

/**
 * @brief Identify whether ray position is outside of map boundaries.
 *
 * @param data Check the map dimensions and grid.
 * @param ray Check the ray's grid position against the map.
 *
 * @return int Return a number to signify whether it's outside the map.
 */
static int	is_outside_map(t_data *data, t_ray *ray)
{
	if (ray->grid.y < 0 || ray->grid.y >= data->map.height)
		return (1);
	if (ray->grid.x < 0 || ray->grid.x >= data->map.width)
		return (1);
	if (!data->map.grid[ray->grid.y])
		return (1);
	if (ray->grid.x >= (int)ft_strlen(data->map.grid[ray->grid.y]))
		return (1);
	return (0);
}

/**
 * @brief Walk the ray through the map until it hits a wall.
 *
 * @param data Game data containing the map.
 * @param ray Ray structure to update.
 */
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
		if (is_outside_map(data, ray))
		{
			ray->hit = 1;
			break ;
		}
		if (data->map.grid[ray->grid.y][ray->grid.x] == '1')
			ray->hit = 1;
	}
}

void	cast_ray(t_data *data, int x, t_ray *ray)
{
	double	camera_x;

	init_ray(data, ray);
	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir.x = data->player.dir.x + data->player.plane.x * camera_x;
	ray->dir.y = data->player.dir.y + data->player.plane.y * camera_x;
	set_ray_step(ray);
	set_ray_delta_dist(ray);
	set_ray_side_dist(ray);
	ray->hit = 0;
	dda_loop(data, ray);
	if (ray->hit == 1)
	{
		compute_perp_wall_dist(ray);
		draw_wall_column(data, ray, x);
	}
}
