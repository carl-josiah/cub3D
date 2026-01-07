/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:20:02 by ccastro           #+#    #+#             */
/*   Updated: 2026/01/07 22:09:55 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_tex_mask
{
	TEX_NO = 1 << 0,
	TEX_SO = 1 << 1,
	TEX_EA = 1 << 2,
	TEX_WE = 1 << 3,
	TEX_F = 1 << 4,
	TEX_C = 1 << 5,
	TEX_ALL = TEX_NO | TEX_SO | TEX_EA | TEX_WE | TEX_F | TEX_C
}	t_tex_mask;

typedef enum e_state
{
	STATE_CONFIG,
	STATE_MAP
}	t_state;

#endif
