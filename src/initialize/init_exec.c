/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:51:26 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:16:38 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	init_img(&mlx->screen);
}
