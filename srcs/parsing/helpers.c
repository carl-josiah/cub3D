/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:33:12 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/10 16:35:34 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

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

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
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
	if (*id)
	{
		if (*id & tex->mask)
			return (TEX_DUPLICATE);
	}
	else if (ft_is_empty(line))
		return (TEX_SPACES);
	else if (ft_is_included(line, MAP))
		return (TEX_MAP);
	else if (!*id)
		return (TEX_INVALID);
	return (TEX_VALID);
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
