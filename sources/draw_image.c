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

//static void	draw_background(t_mlx *m)
//{
//	int	*image;
//	int	i;
//
//	ft_bzero(m->data, SIZE_X * SIZE_Y * (m->bpp / 8));
//	image = (int *)(m->data);
//	i = 0;
//	while (i < SIZE_X * SIZE_Y)
//	{
//		image[i] = 0x101010;
//		i++;
//	}
//}

int		check_swap(int *x0, int *y0, int *x1, int *y1)
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

void	p_draw_image(t_mlx *m)
{
	mlx_put_image_to_window(m->ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	line(int p1[2], int p2[2], t_mlx *m)
{
	int 	x;
	int 	y;
	int 	err;
	int 	flag;
	int 	i;

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

void 	toISO(int *x, int *y, int z)
{
    int 	p_x;
    int 	p_y;

    p_x = *x;
    p_y = *y;
    *x = (int)((p_x - p_y) * cos(0.523599));
    *y = (int)(-z + (p_x + p_y) * sin(0.523599));
}

void	check_coord(int *x, int *y, t_mlx *m, int point[2])
{
	*x *= m->zoom;
	*y *= m->zoom;

	*x -= (m->map_h * m->zoom) / 2;
	*y -= (m->map_w * m->zoom) / 2;

	if (m->p_i == 1)
		toISO(x, y, m->mmap[point[1]][point[0]] * m->zoom);
	*x += (SIZE_X / 2);
	*y += (SIZE_Y + m->map_w * m->zoom) / 2;
}

void	draw_line(int p1[2], int p2[2], t_mlx *m)
{
	int 	f[2];
	int 	s[2];

	f[0] = p1[0];
	f[1] = p1[1];
	s[0] = p2[0];
	s[1] = p2[1];
	check_coord(&(f[0]), &(f[1]), m, p1);
	check_coord(&(s[0]), &(s[1]), m, p2);

	line(f, s, m);

}

void	draw_image(t_mlx *m)
{
	int 	x;
	int 	y;
	int 	p1[2];
	int 	p2[2];

	y = 0;

//	draw_background(m);
	while(y < m->map_w)
	{

		x = 0;
		while (x < m->map_h)
		{
			p1[0] = x;
			p1[1] = y;
			p2[0] = x + 1;
			p2[1] = y;
			printf("1  (%d %d) : (%d %d)\n", p1[0], p1[1], p2[0], p2[1]);
			if (x != m->map_h - 1)
				draw_line(p1, p2, m);
			p2[0] = x;
			p2[1] = y + 1;
			printf("2  (%d %d) : (%d %d)\n", p1[0], p1[1], p2[0], p2[1]);
			if (y != m->map_w - 1)
				draw_line(p1, p2, m);
			x++;
		}
		y++;
	}

}