/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 03:00:58 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/04 15:01:12 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit


void	ex_error(int num)
{
	char 	*write_err;

	if (num == 1)
		write_err = "Not one argument\n";
	else if (num == 2)
		write_err = "Can't work with file\n";
	else if (num == 3)
		write_err = "Not valid map\n";
	else if (num == 4)
		write_err = "Can't malloc memory\n";
	else if (num == -1)
		write_err = "debug";
	write(2, write_err, ft_strlen(write_err) + 1);
	exit(EXIT_FAILURE);
}

int		main(int argv, char **argc)
{
	t_mlx	*mlx;
	//int 	fd;


	if (argv != 2)
		ex_error(1);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		ex_error(4);
	mlx = ft_init(mlx, argc[1]);
	draw_image(mlx);
	//mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	controls(mlx);
	mlx_loop(mlx->ptr);
}
