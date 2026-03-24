/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:03:27 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 12:17:15 by ccastro          ###   ########.fr       */
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
			parse_direction(*id, line, data);
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
	if (ft_is_empty(line))
		exit_error(data, EMPTY_LINE, NULL, NL);
	if (!ft_str_has_charset(line, MAP_CHARS))
		exit_error(data, MAP_INVALID_CHARS, line, NO_NL);
	data->file.map_line = ft_strtrim(line, "\n");
	if (!data->file.map_line)
		exit_error(data, MALLOC, NULL, NL);
	store_map_line(data->file.map_line, data);
	data->tex.mask |= TEX_MAP_MASK;
}

static void	handle_line(char *line, t_data *data, t_state *state)
{
	int	id;

	if (ft_strchr(line, '\r'))
		exit_error(data, ERROR_CRLF, NULL, NL);
	if (*state == STATE_CONFIG)
		handle_config(line, data, &id, state);
	else if (*state == STATE_MAP)
		handle_map(line, data);
}

static int	allocate_grid(char **lines, t_data *data)
{
	data->map.height = count_map_height(lines);
	data->map.grid = ft_calloc(sizeof(char *), (data->map.height + 1));
	if (!data->map.grid)
		exit_error(data, MALLOC, NULL, NL);
	return (1);
}

void	parse_file(char **lines, t_data *data)
{
	t_state	state;
	int		flag;

	state = STATE_CONFIG;
	flag = 0;
	if (!*lines)
		exit_error(data, EMPTY_FILE, NULL, NL);
	while (*lines)
	{
		handle_line(*lines, data, &state);
		if (state == STATE_MAP && flag == 0)
			flag = allocate_grid(lines, data);
		else
			lines++;
	}
	if ((data->tex.mask & TEX_DIR) != TEX_DIR)
		throw_direction_error(data);
	if ((data->tex.mask & TEX_COLOR) != TEX_COLOR)
		throw_color_error(data);
	if ((data->tex.mask & TEX_MAP_MASK) != TEX_MAP_MASK)
		exit_error(data, MISSING_MAP, NULL, NL);
	validate_map(data->map.grid, data);
}
