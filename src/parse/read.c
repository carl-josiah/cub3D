/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:22 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/24 13:15:07 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static size_t	count_lines(int fd)
{
	char	*line;
	size_t	line_count;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_count++;
		free(line);
	}
	return (line_count);
}

static char	**get_lines(int fd, size_t line_count)
{
	size_t	i;
	char	**lines;
	char	*line;

	i = 0;
	lines = ft_calloc(line_count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	while (i < line_count)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_double_ptr(lines);
			line = get_next_line(fd);
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (NULL);
		}
		lines[i++] = line;
	}
	return (lines);
}

static int	check_cube_file(t_data *data, const char *cub_file)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		exit_error(data, INVALID_FILE, NULL, NL);
	return (fd);
}

char	**read_cub_file(t_data *data, const char *cub_file, size_t *lc)
{
	int		fd;
	char	**lines;
	char	*tmp;

	fd = check_cube_file(data, cub_file);
	*lc = count_lines(fd);
	close(fd);
	fd = check_cube_file(data, cub_file);
	lines = get_lines(fd, *lc);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	if (!lines)
		return (NULL);
	return (lines);
}
