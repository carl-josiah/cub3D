/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:33:12 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/26 17:34:06 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static int	is_map_char(char c)
{
	return (ft_strchr("01NSEW"SPACES, c) != NULL);
}

int	is_empty(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line))
			return (0);
		line++;
	}
	return (1);
}

void	skip_white_spaces(char **line, int skip) 
{
	line += skip;
	while (**line && ft_isspace(**line))
		(*line)++;
}

void	throw_id_error(int id, t_tex *tex)
{
	if (id == -1)
		exit_error("Invalid texture identifier", NULL);
	else if (id == 0)
		return ;
	else if (id & tex->mask && id & TEX_DIR)
		exit_error("Duplicate texture identifier", NULL);
	else if (id & tex->mask && id & TEX_COLOR)
		exit_error("Duplicate color identifier", NULL);
}
