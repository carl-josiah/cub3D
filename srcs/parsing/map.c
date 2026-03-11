/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/03/10 11:56:22 by ccastro          ###   ########.fr       */
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
