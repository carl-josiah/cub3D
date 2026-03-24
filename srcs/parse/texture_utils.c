/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:33:12 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:20:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	forbid_garbage(char *ptr, char *line)
{
	if (!ft_isdigit(*ptr))
		exit_error(NULL, INVALID_COLOR, line, NO_NL);
	while (ft_isdigit(*ptr))
		ptr++;
	while (ft_isspace(*ptr))
		ptr++;
	if (!*ptr)
		exit_error(NULL, INVALID_COLOR, line, NO_NL);
}

static t_tex_status	acquire_tex(int id, char *line, t_tex *tex)
{
	if (id)
	{
		if (id & tex->mask)
			return (TEX_DUPLICATE);
	}
	if (ft_is_empty(line))
		return (TEX_SPACES);
	if (ft_str_has_charset(line, MAP_CHARS))
		return (TEX_MAP);
	if (!id)
		return (TEX_INVALID);
	return (TEX_VALID);
}

t_tex_status	is_texture(int *id, char *line, t_tex *tex)
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
	return (acquire_tex(*id, line, tex));
}

void	skip_white_spaces(char **line, int skip)
{
	if (!line || !*line)
		return ;
	while (skip > 0 && **line)
	{
		(*line)++;
		skip--;
	}
	while (**line && ft_strchr(SPACES, **line))
		(*line)++;
}

int	parse_rgb_channel(char *ptr, int *rgb, int i)
{
	char	*start;

	start = ptr;
	if (!ft_isdigit(*ptr))
		return (0);
	while (ft_isdigit(*ptr))
		ptr++;
	if (i < 2)
	{
		if (*ptr && *ptr != ',')
			return (0);
	}
	else if (i == 2)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if (*ptr && !ft_isspace(*ptr))
			return (0);
	}
	if (!ft_atoi_safe(start, &rgb[i]))
		return (0);
	if (rgb[i] < 0 || rgb[i] > 255)
		return (0);
	return (1);
}
