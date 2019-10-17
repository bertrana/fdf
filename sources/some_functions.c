/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 02:59:13 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/06 14:52:05 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_d_z(int **map, int h, int w)
{
	int	x;
	int	y;
	int min;
	int max;

	min = 0;
	max = 0;
	y = 0;
	while (y < w)
	{
		x = 0;
		while (x < h)
		{
			max = ft_max(map[y][x], max);
			min = ft_min(map[y][x], min);
			x++;
		}
		y++;
	}
	return (max - min);
}
