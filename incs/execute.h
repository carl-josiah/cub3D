/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:04:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 10:33:07 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <cleanup.h>
# include <debug.h>
# include <defines.h>
# include <math.h>
# include <mlx.h>
# include <structs.h>
# include <sys/time.h>

void	open_window(t_data *data);
void	event_handlers(t_data *data);
void	launch_game(t_data *data);
void	create_image(t_data *data);
void	load_textures(t_data *data);
void	init_ray(t_data *data, t_ray *ray);
void	set_ray_step(t_ray *ray);
void	set_ray_delta_dist(t_ray *ray);
void	set_ray_side_dist(t_ray *ray);
void	pixel_put(t_img *img, int x, int y, int color);
void	cast_ray(t_data *data, int x);
void	render(t_data *data);

#endif
