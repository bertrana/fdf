/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:53:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/04 20:40:10 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			b_close(void *param)
{
	(void)param;
	exit(0);
}

static int	key_2(int keycode, t_mlx *m)
{
	if (keycode == 126)
		m->up_down += 4;
	if (keycode == 125)
		m->up_down -= 4;
	if (keycode == 32)
		m->d_z += 1;
	if (keycode == 2)
		m->d_z -= 1;
	draw_image(m);
	return (0);
}

int			key_press(int keycode, void *param)
{
	t_mlx	*m;

	m = (t_mlx *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 35)
		m->p_i = 0;
	if (keycode == 34)
		m->p_i = 1;
	if (keycode == 78)
		m->zoom--;
	if (keycode == 69)
		m->zoom++;
	if (keycode == 123)
		m->left_right += 4;
	if (keycode == 124)
		m->left_right -= 4;
	return (key_2(keycode, m));
}

void		controls(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 0, b_close, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
}
