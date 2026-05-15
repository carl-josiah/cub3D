/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:44:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/14 15:28:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <enums.h>
# include <stdlib.h>

typedef struct s_tex
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			f;
	int			c;
	t_tex_mask	mask;
}				t_tex;

typedef struct s_map
{
	char		**grid;
	int			row;
	int			height;
	int			width;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_dir
{
	double		x;
	double		y;
}				t_dir;

typedef struct s_grid
{
	int			x;
	int			y;
}				t_grid;

typedef struct s_step
{
	int			x;
	int			y;
}				t_step;

typedef struct s_dist
{
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
}				t_dist;

typedef struct s_ray
{
	t_pos		pos;
	t_dir		dir;
	t_grid		grid;
	t_step		step;
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
