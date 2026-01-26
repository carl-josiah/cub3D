/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:53:40 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/26 17:45:00 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <string.h>

static int
	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char
	*f_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

void	parse_direction(int id, char *line, t_tex *tex)
{
	char	*texture;

	skip_white_spaces(&line, 2);
	texture = f_strtrim(line, SPACES);
	// if (!texture)
	// 	exit_error(MALLOC, NULL);
	// if (id == TEX_NO)
	// 	tex->no = texture;
	// else if (id == TEX_SO)
	// 	tex->so = texture;
	// else if (id == TEX_EA)
	// 	tex->ea = texture;
	// else if (id == TEX_WE)
	// 	tex->we = texture;
	// else if (id == TEX_F || id == TEX_C)
	// 	return ;
	// tex->mask |= id;
}

void	parse_color(int id, char *line, t_tex *tex)
{
	// char	*texture;
	//
	// skip_white_spaces(&line, 1);
	// texture = ft_strtrim(line, SPACES);
	// if (!texture)
	// 	exit_error(MALLOC, NULL);
	// if (id == TEX_F)
	// 	tex->f = texture;
	// else if (id == TEX_C)
	// 	tex->c = 
}
