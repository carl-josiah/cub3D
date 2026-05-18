/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:07:39 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:42:30 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

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

void	print_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		printf("row[%i]: %s\n", i, grid[i]);
		i++;
	}
}

void	print_texture_paths(t_data *data)
{
	printf("tex[0]: %s\n", data->tex.no);
	printf("tex[1]: %s\n", data->tex.so);
	printf("tex[2]: %s\n", data->tex.we);
	printf("tex[3]: %s\n", data->tex.ea);
}

void	print_center_ray(t_ray *ray)
{
	printf("grid.x: %d\n", ray->grid.x);
	printf("grid.y: %d\n", ray->grid.y);
	printf("dist.side_x: %f\n", ray->dist.side_x);
	printf("dist.side_y: %f\n", ray->dist.side_y);
	printf("side: %d\n", ray->side);
}
