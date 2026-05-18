/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:06:24 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 18:15:25 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

t_img	*get_wall_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			return (&data->textures[2]);
		return (&data->textures[3]);
	}
	if (ray->dir.y > 0)
		return (&data->textures[0]);
	return (&data->textures[1]);
}

int	get_texture_color(t_img *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}
