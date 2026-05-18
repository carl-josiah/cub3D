/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/15 14:46:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	flood_fill(char **grid, int x, int y, int height)
{
	int	len;

	if (y < 0 || y >= height)
		return (0);
	len = ft_strlen(grid[y]);
	if (x < 0 || x >= len || !grid[y][x])
		return (0);
	if (grid[y][x] == ' ' || grid[y][x] == '\t' || grid[y][x] == '\n')
		return (0);
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return (1);
	grid[y][x] = 'V';
	if (!flood_fill(grid, x, y - 1, height))
		return (0);
	if (!flood_fill(grid, x, y + 1, height))
		return (0);
	if (!flood_fill(grid, x - 1, y, height))
		return (0);
	if (!flood_fill(grid, x + 1, y, height))
		return (0);
	return (1);
}

static int	validate_flood_fill(char **cpy, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (cpy[y][x])
		{
			if (cpy[y][x] == '0' || cpy[y][x] == 'N' || cpy[y][x] == 'S'
				|| cpy[y][x] == 'E' || cpy[y][x] == 'W')
			{
				if (!flood_fill(cpy, x, y, height))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	is_map_closed(t_data *data)
{
	char	**cpy;
	int		is_closed;

	cpy = copy_grid(data->map.grid, data->map.height);
	if (!cpy)
		return (0);
	is_closed = validate_flood_fill(cpy, data->map.height);
	free_grid(cpy, data->map.height);
	return (is_closed);
}

void	validate_map(char **grid, t_data *data)
{
	if (count_directions(grid, data->map.height) != 1)
		exit_error(data, MAP_ERROR_DIR, NULL, NL);
	find_player(data);
	if (!is_map_closed(data))
		exit_error(data, MAP_NOT_CLOSED, NULL, NL);
}
