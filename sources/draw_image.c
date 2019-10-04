/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 03:01:05 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/04 16:30:08 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(t_mlx *m)
{
	int	*image;
	int	i;

	ft_bzero(m->data, SIZE_X * SIZE_Y * (m->bpp / 8));
	image = (int *)(m->data);
	i = 0;
	while (i < SIZE_X * SIZE_Y)
	{
		image[i] = 0x101010;
		i++;
	}
}

void	line(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	int x;
	int y;
	int flag;
	int err;
	int cen;

	cen = SIZE_X * 20 + 20;
	flag = 0;
	if (abs(x0 - x1) < abs(y0 - y1))
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
		flag = 1;
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	x = x0;
	y = y0;
	err = 0;
	while (x++ <= x1)
	{
		mlx->data[cen + (flag ? (x * SIZE_X + y) : (y * SIZE_X + x))] = 0xffff00;
		err += abs(y1 - y0) * 2;
		if (err > x1 - x0)
		{
			y += (y1 > y0 ? 1 : -1);
			err -= (x1 - x0) * 2;
		}
	}
}

void	i_draw_image(t_mlx *m)
{
	int 	x;
	int 	y;
	int 	coef;

	mlx_clear_window(m->ptr, m->win_ptr);
	y = 1;
	coef = 40;
	while (y < m->map_w * coef)
	{
		x = 1;
		while (x < m->map_h * coef)
		{
			if (y != (m->map_w - 1) * coef)
				line(x, y, x + coef, y, m);
			if (x != (m->map_h - 1) * coef)
				line(x, y, x, y + coef, m);
			x = x + coef;
		}
		y = y + coef;
	}
	line(x, 0, x, y, m);
	line(0, y, x, y, m);
	//mlx_clear_window(m->ptr, m->win_ptr);
	mlx_put_image_to_window(m->ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	p_draw_image(t_mlx *m)
{
	int 	x;
	int 	y;
	int 	coef;

	mlx_clear_window(m->ptr, m->win_ptr);
	y = 1;
	coef = 25;
	while (y < m->map_w * coef)
	{
		x = 1;
		while (x < m->map_h * coef)
		{
			if (y != (m->map_w - 1) * coef)
				line(x, y, x + coef, y, m);
			if (x != (m->map_h - 1) * coef)
				line(x, y, x, y + coef, m);
			x = x + coef;
		}
		y = y + coef;
	}
	line(x, 0, x, y, m);
	line(0, y, x, y, m);

	mlx_put_image_to_window(m->ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	draw_image(t_mlx *m)
{
	draw_background(m);
	if (m->p_i == 0)
		p_draw_image(m);
	else if (m->p_i == 1)
	{
		i_draw_image(m);
	}
}