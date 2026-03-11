/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:07:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/08 00:51:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

int	print_for_me(const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	print_grid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		if (data->map.grid[i])
			printf("row[%i]: %s\n", i, data->map.grid[i]);
		i++;
	}
}
