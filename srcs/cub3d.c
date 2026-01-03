/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carljosiah <carljosiah@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:36 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/03 19:12:47 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;

	args_validation(ac, av);
	init_data(&data);
	return (EXIT_SUCCESS);
}
