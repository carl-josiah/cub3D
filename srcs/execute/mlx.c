/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:07:44 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/08 19:06:00 by carljosiah       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

void	open_window(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		exit_error(data, ERROR_MLX_INIT, NULL, NL);
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, CUB3D);
	if (!data->mlx.win)
		exit_error(data, ERROR_MLX_WIN, NULL, NL);
}
