/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:22 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/16 16:19:11 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

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
			while ((line = get_next_line(fd)))
				free(line);
			return (NULL);
		}
		lines[i] = line;
		i++;
	}
	return (lines);
}

char	**read_cub_file(const char *cub_file, size_t *lc)
{
	int		fd;
	char	**lines;
	char	*tmp;

	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	*lc = count_lines(fd);
	close(fd);
	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = get_lines(fd, *lc);
	while ((tmp = get_next_line(fd)))
		free(tmp);
	close(fd);
	if (!lines)
		return (NULL);
	return (lines);
}
