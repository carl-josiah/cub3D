/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:03:49 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/16 18:54:34 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	count_directions(char **grid, int height)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < height)
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**copy_grid(char **grid, int height)
{
	int		i;
	char	**copied_grid;

	i = 0;
	copied_grid = ft_calloc(sizeof(char *), height + 1);
	if (!copied_grid)
		return (NULL);
	while (i < height)
	{
		copied_grid[i] = ft_strdup(grid[i]);
		if (!copied_grid[i])
		{
			free_grid(copied_grid, height);
			return (NULL);
		}
		i++;
	}
	return (copied_grid);
}
