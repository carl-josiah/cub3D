/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:30:45 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:29:22 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	free_mlx(t_data *data)
{
	if (data->mlx.screen.img)
		mlx_destroy_image(data->mlx.ptr, data->mlx.screen.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mlx.ptr)
		mlx_destroy_display(data->mlx.ptr);
}
