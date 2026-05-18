/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:18:15 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:17:31 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "structs.h"

void	init_tex(t_tex *tex);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_file(t_file *file);
void	init_img(t_img *img);
void	init_mlx(t_mlx *mlx);
void	init_data(t_data *data);

#endif
