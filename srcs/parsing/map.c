/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:53:10 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/24 12:07:55 by ccastro          ###   ########.fr       */
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

int	consume_map_line(char *line, t_data *data)
{
	if (!line || !*line)
		return (0);
	return (1);
}
