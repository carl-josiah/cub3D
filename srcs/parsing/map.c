/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:11:06 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/08 01:09:35 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

void	store_map_line(t_map *map, char *line)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->grid && map->grid[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		exit_error("Memory allocation failure", NULL);
	while (j < i)
	{
		new[j] = map->grid[j];
		j++;
	}
	new[i] = ft_strdup(line);
	if (!new[i])
		exit_error("Memory allocation failure", (void **)&new);
	new[i + 1] = NULL;
	free(map->grid);
	map->grid = new;
}
