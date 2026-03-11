/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:44:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/11 17:35:16 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <enums.h>

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
	char	**grid;
	int		row;
	int		height;
	int		width;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}			t_player;

typedef struct s_file
{
	char	**lines;
}			t_file;

typedef struct s_data
{
	t_tex		tex;
	t_map		map;
	t_player	player;
	t_file		file;
	// t_mlx
}				t_data;

#endif
