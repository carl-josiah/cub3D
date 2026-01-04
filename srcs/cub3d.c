/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/04 17:00:31 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#define DEBUG 1

int	main(int ac, char **av)
{
	t_data	data;

	if (DEBUG)
	{
		print_for_me("maps/map.cub");
	}
	else
	{
		args_validation(ac, av);
		init_data(&data);
	}
	return (EXIT_SUCCESS);
}
