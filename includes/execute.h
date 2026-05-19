/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:04:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 17:46:52 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cleanup.h"
# include "debug.h"
# include "defines.h"
# include <math.h>
# include <mlx.h>
# include <structs.h>
# include <sys/time.h>

/**
 * @brief Calls all functions related to raycasting and rendering.
 *
 * @param data Game data structure containing all.
 */
void	launch_game(t_data *data);

/**
 * @brief Initialize the mlx and create the window.
 *
 * @param data Update the data's mlx struct.
 */
void	open_window(t_data *data);

/**
 * @brief Handle keystrokes and window events.
 *
 * @param data Call on data's mlx to set hooks.
 */
void	event_handlers(t_data *data);

/**
 * @brief Create the buffer for the pixels to be drawn.
 *
 * @param data Call on data's mlx to contain the image and the address for it.
 */
void	create_image(t_data *data);

/**
 * @brief Convert xpm files and load the pixels into the memory.
 *
 * @param data Call on data's mlx to contain the textures.
 */
void	load_textures(t_data *data);

/**
 * @brief Initialize ray data from the player state.
 *
 * @param data Game data containing player position and direction.
 * @param ray Ray structure to fill.
 */
void	init_ray(t_data *data, t_ray *ray);

/**
 * @brief Set the ray step direction in the map grid.
 *
 * @param ray Ray structure to update.
 */
void	set_ray_step(t_ray *ray);

/**
 * @brief Computer how far the ray must travel to cross one grid cell.
 *
 * @param ray Ray structure to update.
 */
void	set_ray_delta_dist(t_ray *ray);

/**
 * @brief Compute the distance from the ray to the next grid edge.
 *
 * @param ray Ray structure to update.
 */
void	set_ray_side_dist(t_ray *ray);

/**
 * @brief Write one pixel in the image buffer.
 *
 * @param img Image to write to.
 * @param x X coordinate.
 * @param y Y coordinate.
 * @param color Pixel color in RGB format.
 */
void	pixel_put(t_img *img, int x, int y, int color);

/**
 * @brief Draw one vertical wall stripe on the screen.
 *
 * @param data Game data and screen image.
 * @param ray Ray structure to update.
 * @param x Screen column to draw.
 */
void	draw_wall_column(t_data *data, t_ray *ray, int x);

/**
 * @brief Cast a ray, find wall hit, and draw one vertical wall stripe.
 *
 * @param data Game data and rendering state.
 * @param x Screen column to draw.
 * @param ray Fill ray structure from caller.
 */
void	cast_ray(t_data *data, int x, t_ray *ray);

/**
 * @brief Render the current frame.
 *
 * @param data Game data and rendering state.
 */
void	render(t_data *data);

/**
 * @brief Select wall texture based on ray hit side and direction.
 *
 * @param data Game data containing textures
 * @param ray Ray hit information.
 *
 * @return t_img *Pointer to the selected texture.
 */
t_img	*get_wall_texture(t_data *data, t_ray *ray);

/**
 * @brief identify
 *
 * @param tex
 * @param x
 * @param y
 *
 * @return int
 */
int		get_texture_color(t_img *tex, int x, int y);

t_vec2i	get_draw_bounds(int line_height);

t_vec2i	get_clamped_bounds(t_vec2i raw_bounds);

double	get_wall_x(t_ray *ray);

int		get_tex_x(t_ray *ray, t_img *tex);

int		get_tex_y(int y, int draw_start, int line_height, t_img *tex);

void	draw_textured_line(t_data *data, t_ray *ray, int x, t_wall_draw *wall);

void	initialize_input_keys(t_data *data);

void	move_player(t_data *data);

/**
 * @brief Callback function that changes the state of the game
 * or exits the game.
 *
 * @param keycode The code of the key pressed.
 * @param data The struct to pass to the function called.
 *
 * @return int Returns a number due to mlx_key_hook() implementation.
 */
int		on_key_press(int keycode, t_data *data);

/**
 * @brief Callback function that changes the state of the game on key release.
 *
 * @param keycode The code of the key pressed.
 * @param data The struct to pass to the function called.
 *
 * @return int Returns a number due to mlx_key_hook() implementation.
 */
int		on_key_release(int keycode, t_data *data);

/**
 * @brief Callback function that identify the window close event.
 *
 * @param data Pass data struct.
 * @return int Returns a number due to mlx_hook() implementation.
 */
int		on_window_close(t_data *data);

#endif
