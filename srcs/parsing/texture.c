/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:53:40 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/11 17:26:24 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	validate_line_argc(char *line)
{
	size_t	count;

	count = ft_count_words(line, SPACES);
	if (count <= 1)
		exit_error(NULL, NO_TEXTURE, line, NO_NL);
	if (count > 2)
		exit_error(NULL, INVALID_TEXTURE, line, NO_NL);
}

static void	extract_color(char *line, int *rgb)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = line;
	skip_white_spaces(&ptr, 1);
	while (i < 3)
	{
		if (!error_check(ptr, rgb, i))
			exit_error(NULL, INVALID_COLOR, line, NO_NL);
		ptr += ft_strcspn(ptr, ",");
		if (i < 2)
		{
			if (*ptr && *ptr != ',')
				exit_error(NULL, INVALID_COLOR, line, NO_NL);
			ptr++;
		}
		i++;
	}
	if (*ptr && !ft_isspace(*ptr))
		exit_error(NULL, INVALID_COLOR, line, NO_NL);
}

static int	path_validation(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	parse_direction(int id, char *line, t_data *data)
{
	char	*texture;

	validate_line_argc(line);
	skip_white_spaces(&line, 2);
	texture = ft_strtrim(line, SPACES);
	if (!texture)
		exit_error(data, MALLOC, NULL, NL);
	if (!path_validation(texture))
	{
		free(texture);
		exit_error(data, INVALID_PATH, texture, NL);
	}
	if (id == TEX_NO)
		data->tex.no = texture;
	else if (id == TEX_SO)
		data->tex.so = texture;
	else if (id == TEX_EA)
		data->tex.ea = texture;
	else if (id == TEX_WE)
		data->tex.we = texture;
	data->tex.mask |= id;
}

void	parse_color(int id, char *line, t_tex *tex)
{
	int		rgb[3];

	extract_color(line, rgb);
	if (id == TEX_F)
		tex->f = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	else if (id == TEX_C)
		tex->c = rgb_to_int(rgb[0], rgb[1], rgb[2]);
	tex->mask |= id;
}
