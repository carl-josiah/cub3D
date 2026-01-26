/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:32:33 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/26 17:35:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static t_tex_status	is_texture_or_color(int *id, char *line, t_tex *tex)
{
	*id = 0;
	if (!ft_strncmp(line, "NO", 2) && ft_isspace(line[2]))
		*id = TEX_NO;
	else if (!ft_strncmp(line, "SO", 2) && ft_isspace(line[2]))
		*id = TEX_SO;
	else if (!ft_strncmp(line, "EA", 2) && ft_isspace(line[2]))
		*id = TEX_EA;
	else if (!ft_strncmp(line, "WE", 2) && ft_isspace(line[2]))
		*id = TEX_WE;
	else if (!ft_strncmp(line, "F", 1) && ft_isspace(line[1]))
		*id = TEX_F;
	else if (!ft_strncmp(line, "C", 1) && ft_isspace(line[1]))
		*id = TEX_C;
	if (*id)
	{
		if (*id & tex->mask)
			return (TEX_DUPLICATE);
	}
	else if (is_empty(line))
		return (TEX_INVALID);
	else if (is_map_line(line))
		return (TEX_MAP);
	tex->mask |= *id; // ilagay sa parse_direction function
	return (TEX_VALID);
}

static int num_line = 1;

static void	handle_config(char *line, t_tex *tex, int *id)
{
	t_tex_status	status;

	*id = 0;
	skip_white_spaces(&line, 0);
	status = is_texture_or_color(id, line, tex);
	if (status == TEX_VALID)
	{
		if (*id & TEX_DIR)
		{
			printf("Tex [%d]\n", num_line);
			parse_direction(*id, line, tex);
		}
		else if (*id & TEX_COLOR)
			printf("Col [%d]\n", num_line);
			// parse_color(*id, line, tex);
	}
	else if (status == TEX_INVALID)
	{
		printf("Bad [%d]\n", num_line);
		// exit_error(INVALID, NULL);
	}
	else if (status == TEX_DUPLICATE)
	{
		printf("Dup [%d]\n", num_line);
		// exit_error(DUPLICATE, NULL);
	}
	else if (status == TEX_MAP)
	{
		printf("Map [%d]\n", num_line);
		// return ;
	}
	num_line++;
}

static void	handle_line(char *line, t_data *data, t_state *state)
{
	int	id;

	if (*state == STATE_CONFIG)
		handle_config(line, &data->tex, &id);
	else if (*state == STATE_MAP)
		;
}

void	parse_file(char **lines, t_data *data)
{
	t_state	state;

	state = STATE_CONFIG;
	while (*lines)
	{
		handle_line(*lines, data, &state);
		lines++;
	}
}
