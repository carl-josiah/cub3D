/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:44:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 17:38:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"
# include <stdlib.h>

typedef struct s_tex
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			floor_color;
	int			ceiling_color;
	t_tex_mask	mask;
}				t_tex;

typedef struct s_map
{
	char		**grid;
	int			row;
	int			height;
	int			width;
}				t_map;

typedef struct s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		plane;
}				t_player;

typedef struct s_dist
{
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
}				t_dist;

typedef struct s_ray
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2i		grid;
	t_vec2i		step;
	t_dist		dist;
	int			hit;
	int			side;
	double		perp_wall_dist;
}				t_ray;

typedef struct s_file
{
	char		**lines;
	size_t		line_count;
	char		*map_line;
}				t_file;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_img		screen;
}				t_mlx;

typedef struct s_data
{
	t_tex		tex;
	t_map		map;
	t_player	player;
	t_file		file;
	t_mlx		mlx;
	t_img		textures[TEX_COUNT];
}				t_data;

#endif
