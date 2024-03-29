/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:06:15 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/05 17:26:59 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(int *x, int *y, int z, int d_z)
{
	int		p_x;
	int		p_y;

	p_x = *x;
	p_y = *y;
	*x = (int)((p_x - p_y) * cos(0.523599));
	if (z != 0)
		if (z < 0)
			*y = (int)(-(z + d_z) + (p_x + p_y) * sin(0.523599));
		else
			*y = (int)(-(z - d_z) + (p_x + p_y) * sin(0.523599));
	else
		*y = (int)(-z + (p_x + p_y) * sin(0.523599));
}

void	check_coord(int *x, int *y, t_mlx *m, int point[2])
{
	*x *= m->zoom;
	*y *= m->zoom;
	*x -= (m->map_h * m->zoom) / 2;
	*y -= (m->map_w * m->zoom) / 2;
	if (m->p_i == 1)
		to_iso(x, y, (m->mmap[point[1]][point[0]]) * m->zoom, m->d_z);
	*x += (SIZE_X / 2) + m->left_right;
	*y += (SIZE_Y + m->map_w * m->zoom) / 2 + m->up_down;
}
