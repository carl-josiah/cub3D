/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:32:33 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/01 16:43:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	handle_config(char *line, t_tex *tex, int *id, t_state *state)
{
	t_tex_status	status;

	*id = 0;
	skip_white_spaces(&line, 0);
	status = is_texture(id, line, tex);
	if (status == TEX_VALID)
	{
		if (*id & TEX_DIR)
			parse_direction(*id, line, tex);
		else if (*id & TEX_COLOR)
			parse_color(*id, line, tex);
	}
	else if (status == TEX_SPACES)
		return ;
	else if (status == TEX_DUPLICATE)
		exit_error(DUPLICATE_TEXTURE, line, NO_NL);
	else if (status == TEX_INVALID)
		exit_error(INVALID_IDENTIFIER, line, NO_NL);
	else if (status == TEX_MAP)
		*state = STATE_MAP;
}

static void	handle_line(char *line, t_data *data, t_state *state)
{
	int	id;

	if (*state == STATE_CONFIG)
		handle_config(line, &data->tex, &id, state);
	if (*state == STATE_MAP)
		;
}

void	parse_file(char **lines, t_data *data)
{
	t_state	state;

	state = STATE_CONFIG;
	if (!*lines)
		exit_error(EMPTY_FILE, NULL, NL);
	while (*lines)
	{
		handle_line(*lines, data, &state);
		lines++;
	}
	if (data->tex.mask != TEX_DIR)
		throw_direction_error(data->tex.mask);
	// if (!(data->tex.mask & TEX_COLOR))
	// 	throw_color_error(data->tex.mask);
}
