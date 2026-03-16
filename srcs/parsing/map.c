/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/16 15:43:28 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <parsing.h>

int	count_map_height(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	return (i);
}

void	store_map_line(char *map_line, t_data *data)
{
	if (data->map.row < data->map.height && map_line)
	{
		data->map.grid[data->map.row] = ft_strdup(map_line);
		if (!data->map.grid[data->map.row])
			exit_error(data, MALLOC, NULL, NL);
		data->map.row++;
	}
	free(map_line);
}

static int	count_directions(char *row)
{
	int	count;

	count = 0;
	while (*row)
	{
		if (*row == 'N' || *row == 'S' || *row == 'E' || *row == 'W')
			count++;
		row++;
	}
	return (count);
}

int	valid_map(char **grid, t_data *data)
{
	int	i;
	int	directions;

	i = 0;
	directions = 0;
	while (i < data->map.height)
	{
		directions += count_directions(grid[i]);
		i++;
	}
	if (directions != 1)
		return (0);
	return (1);
}
