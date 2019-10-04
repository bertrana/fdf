/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:53:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/04 16:25:15 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		b_close(void *param)
{
	(void)param;
	exit(0);
}

int 	key_press(int keycode, void *param)
{
	t_mlx	*m;

	m = (t_mlx *)param;

	if (keycode == 53)
		exit(0);
	if (keycode == 35)
		m->p_i = 0;
	if (keycode == 34)
		m->p_i = 1;
	draw_image(m);
	return (0);
}

void	controls(t_mlx *mlx)
{

	mlx_hook(mlx->win_ptr, 17, 0, b_close, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
}