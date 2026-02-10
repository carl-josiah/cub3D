/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:37:11 by ccastro           #+#    #+#             */
/*   Updated: 2026/02/08 16:37:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleanup.h>

void	free_double_ptr(char **ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_textures(t_tex *tex)
{
	if (tex->no)
		free(tex->no);
	if (tex->so)
		free(tex->so);
	if (tex->ea)
		free(tex->ea);
	if (tex->we)
		free(tex->we);
	tex->no = NULL;
	tex->so = NULL;
	tex->ea = NULL;
	tex->we = NULL;
}
