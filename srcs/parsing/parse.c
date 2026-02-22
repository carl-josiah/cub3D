/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:32:33 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/18 07:40:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	handle_config(char *line, t_data *data, int *id, t_state *state)
{
	t_tex_status	status;

	*id = 0;
	skip_white_spaces(&line, 0);
	status = is_texture(id, line, &data->tex);
	if (status == TEX_VALID)
	{
		if (*id & TEX_DIR)
			parse_direction(*id, line, &data->tex);
		else if (*id & TEX_COLOR)
			parse_color(*id, line, &data->tex);
	}
	else if (status == TEX_SPACES)
		return ;
	else if (status == TEX_DUPLICATE)
		exit_error(data, DUPLICATE_TEXTURE, line, NO_NL);
	else if (status == TEX_INVALID)
		exit_error(data, INVALID_IDENTIFIER, line, NO_NL);
	else if (status == TEX_MAP)
		*state = STATE_MAP;
}

static void	handle_map(char *line, t_data *data)
{
	if (*line)
		data->tex.mask |= TEX_MAP_MASK;
	return ;
}

static void	handle_line(char *line, t_data *data, t_state *state)
{
	int	id;

	if (*state == STATE_CONFIG)
		handle_config(line, data, &id, state);
	if (*state == STATE_MAP)
		handle_map(line, data);
}

void	parse_file(char **lines, t_data *data)
{
	t_state	state;
	int		flag;

	state = STATE_CONFIG;
	flag = 0;
	if (!*lines)
		exit_error(NULL, EMPTY_FILE, NULL, NL);
	while (*lines)
	{
		handle_line(*lines, data, &state);
		if (state == STATE_MAP && flag == 0)
		{
			count_map_height(lines);
			flag = 1;
		}
		lines++;
	}
	if ((data->tex.mask & TEX_DIR) != TEX_DIR)
		throw_direction_error(data);
	if ((data->tex.mask & TEX_COLOR) != TEX_COLOR)
		throw_color_error(data);
	if ((data->tex.mask & TEX_MAP_MASK) != TEX_MAP_MASK)
		exit_error(data, MISSING_MAP, NULL, NL);
	// print_grid((const char **)data->map.grid, data->map.height);
}
