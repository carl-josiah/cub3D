/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:07:44 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:19:14 by ccastro          ###   ########.fr       */
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

void	create_image(t_data *data)
{
	data->mlx.screen.img = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->mlx.screen.img)
		exit_error(data, ERROR_MLX_SCREEN_IMG, NULL, NL);
	data->mlx.screen.addr = mlx_get_data_addr(data->mlx.screen.img,
			&data->mlx.screen.bpp, &data->mlx.screen.line_length,
			&data->mlx.screen.endian);
	if (!data->mlx.screen.addr)
		exit_error(data, ERROR_MLX_SCREEN_ADDR, NULL, NL);
}

void	load_one_texture(t_data *data, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx.ptr, path, &tex->width,
			&tex->height);
	if (!tex->img)
		exit_error(data, ERROR_MLX_TEXTURE, NULL, NL);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length,
			&tex->endian);
	if (!tex->addr)
		exit_error(data, ERROR_MLX_SCREEN_ADDR, NULL, NL);
}

void	load_textures(t_data *data)
{
	load_one_texture(data, &data->textures[0], data->tex.no);
	load_one_texture(data, &data->textures[1], data->tex.so);
	load_one_texture(data, &data->textures[2], data->tex.we);
	load_one_texture(data, &data->textures[3], data->tex.ea);
}
