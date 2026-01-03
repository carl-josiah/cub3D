/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:44:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/03 11:10:19 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		f_color;
	int		c_color;
}			t_tex;

typedef struct s_map
{
	char	**grid;
	int		h;
	int		w;
}			t_map;

typedef struct s_data
{
	t_tex	tex;
	t_map	map;
	// t_player
	// t_mlx
}			t_data;

#endif
