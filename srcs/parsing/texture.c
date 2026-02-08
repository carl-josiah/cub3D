/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:53:40 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/01 22:42:39 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	validate_line_argc(char *line)
{
	size_t	count;

	count = ft_count_words(line, SPACES);
	if (count <= 1)
		exit_error(NO_TEXTURE, line, NO_NL);
	if (count > 2)
		exit_error(INVALID_TEXTURE, line, NO_NL);
}

void	parse_direction(int id, char *line, t_tex *tex)
{
	char	*texture;

	validate_line_argc(line);
	skip_white_spaces(&line, 2);
	texture = ft_strtrim(line, SPACES);
	if (!texture)
		exit_error(MALLOC, NULL, NL);
	if (id == TEX_NO)
		tex->no = texture;
	else if (id == TEX_SO)
		tex->so = texture;
	else if (id == TEX_EA)
		tex->ea = texture;
	else if (id == TEX_WE)
		tex->we = texture;
	tex->mask |= id;
}

static int	error_check(char *ptr, int *rgb, int i)
{
	if (!ft_isdigit(*ptr))
		return (0);
	if (!ft_atoi_safe(ptr, &rgb[i]))
		return (0);
	if (rgb[i] < 0 || rgb[i] > 255)
		return (0);
	return (1);
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
			exit_error(INVALID_COLOR, line, NO_NL);
		ptr += ft_strcspn(ptr, ",");
		// printf("amount: %zu\n", num);
		if (i < 2)
		{
			if (*ptr!= ',')
				exit_error(INVALID_COLOR, line, NO_NL);
			ptr++;
		}
		i++;
	}
	if (!ft_isspace(*ptr))
		exit_error(INVALID_COLOR, line, NO_NL);
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
