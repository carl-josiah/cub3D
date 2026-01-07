/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:53:40 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/08 01:06:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static void	parse_north(char *line, t_tex *tex)
{
	char	*tex_no;

	if (!ft_strncmp("NO ", line, 3))
	{
		if (tex->mask & TEX_NO)
			exit_error("Duplicate NO texture", NULL);
		tex_no = ft_strtrim(line + 3, "\t");
		if (!tex_no || !*tex_no)
			exit_error("Invalid NO texture path", NULL);
		tex->no = tex_no;
		tex->mask |= TEX_NO;
		if (DEBUG_PARSE)
			printf("parsed: NO %s\n", tex_no);
	}
}

static void	parse_south(char *line, t_tex *tex)
{
	char	*tex_so;

	if (!ft_strncmp("SO ", line, 3))
	{
		if (tex->mask & TEX_SO)
			exit_error("Duplicate SO texture", NULL);
		tex_so = ft_strtrim(line + 3, "\t");
		if (!tex_so || !*tex_so)
			exit_error("Invalid SO texture path", NULL);
		tex->so = tex_so;
		tex->mask |= TEX_SO;
		if (DEBUG_PARSE)
			printf("parsed: SO %s\n", tex_so);
	}
}

static void	parse_east(char *line, t_tex *tex)
{
	char	*tex_ea;

	if (!ft_strncmp("EA ", line, 3))
	{
		if (tex->mask & TEX_EA)
			exit_error("Duplicate EA texture", NULL);
		tex_ea = ft_strtrim(line + 3, "\t");
		if (!tex_ea || !*tex_ea)
			exit_error("Invalid EA texture path", NULL);
		tex->ea = tex_ea;
		tex->mask |= TEX_EA;
		if (DEBUG_PARSE)
			printf("parsed: EA %s\n", tex_ea);
	}
}

static void	parse_west(char *line, t_tex *tex)
{
	char	*tex_we;

	if (!ft_strncmp("WE ", line, 3))
	{
		if (tex->mask & TEX_WE)
			exit_error("Duplicate WE texture", NULL);
		tex_we = ft_strtrim(line + 3, "\t");
		if (!tex_we || !*tex_we)
			exit_error("Invalid WE texture path", NULL);
		tex->we = tex_we;
		tex->mask |= TEX_WE;
		if (DEBUG_PARSE)
			printf("parsed: WE %s\n", tex_we);
	}
}

void	parse_texture(char *line, t_tex *tex)
{
	parse_north(line, tex);
	parse_south(line, tex);
	parse_east(line, tex);
	parse_west(line, tex);
}
