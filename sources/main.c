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
	//return ;
}

void	line(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	int 			x;
	int 			y;
	int 			flag;
	int 			err;

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
		mlx->data[!flag ? (x * SIZE_X + y) : (y * SIZE_X + x)] = 0xffff00;
		err += abs(y1 - y0) * 2;
		if (err > x1 - x0)
		{
			y += (y1 > y0 ? 1 : -1);
			err -= (x1 - x0) * 2;
		}
	}
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

	line(30, 30, 80, 80, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_loop(mlx->ptr);
}
