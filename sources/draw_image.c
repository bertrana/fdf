/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 03:01:05 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/06 14:56:15 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_background(t_mlx *m)
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

static int		check_swap(int *x0, int *y0, int *x1, int *y1)
{
	int		flag;

	flag = 0;
	if (abs(*x0 - *x1) < abs(*y0 - *y1))
	{
		ft_swap(x0, y0);
		ft_swap(x1, y1);
		flag = 1;
	}
	if (*x0 > *x1)
	{
		ft_swap(x0, x1);
		ft_swap(y0, y1);
	}
	return (flag);
}

static void		line(int p1[2], int p2[2], t_mlx *m)
{
	int		x;
	int		y;
	int		err;
	int		flag;
	int		i;

	flag = check_swap(&(p1[0]), &(p1[1]), &(p2[0]), &(p2[1]));
	x = p1[0];
	y = p1[1];
	err = 0;
	while (x++ <= p2[0])
	{
		i = flag ? (x * SIZE_X + y) : (y * SIZE_X + x);
		if (x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y)
		{
			m->data[i] = 0xffff00;
		}
		err += abs(p2[1] - p1[1]) * 2;
		if (err > p2[0] - p1[0])
		{
			y += (p2[1] > p1[1] ? 1 : -1);
			err -= (p2[0] - p1[0]) * 2;
		}
	}
}

static void		draw_line(int p1[2], int p2[2], t_mlx *m)
{
	int f[2];
	int s[2];

	f[0] = p1[0];
	f[1] = p1[1];
	s[0] = p2[0];
	s[1] = p2[1];
	check_coord(&(f[0]), &(f[1]), m, p1);
	check_coord(&(s[0]), &(s[1]), m, p2);
	line(f, s, m);
}

void			draw_image(t_mlx *m)
{
	int p1[2];
	int p2[2];

	p1[1] = 0;
	draw_background(m);
	while (p1[1] < m->map_w)
	{
		p1[0] = 0;
		while (p1[0] < m->map_h)
		{
			p2[0] = p1[0] + 1;
			p2[1] = p1[1];
			if (p1[0] != m->map_h - 1)
				draw_line(p1, p2, m);
			p2[0] = p1[0];
			p2[1] = p1[1] + 1;
			if (p1[1] != m->map_w - 1)
				draw_line(p1, p2, m);
			p1[0]++;
		}
		p1[1]++;
	}
	mlx_put_image_to_window(m->ptr, m->win_ptr, m->img_ptr, 0, 0);
}
