/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:08:49 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/22 12:14:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

int	error_check(char *ptr, int *rgb, int i)
{
	char	*start;

	start = ptr;
	if (!ft_isdigit(*ptr))
		return (0);
	while (ft_isdigit(*ptr))
		ptr++;
	if (i < 2)
	{
		if (*ptr && *ptr != ',')
			return (0);
	}
	else if (i == 2)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if (*ptr && !ft_isspace(*ptr))
			return (0);
	}
	if (!ft_atoi_safe(start, &rgb[i]))
		return (0);
	if (rgb[i] < 0 || rgb[i] > 255)
		return (0);
	return (1);
}
