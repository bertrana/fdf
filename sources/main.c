
#include "fdf.h"

#define SIZE_X 500
#define SIZE_Y 500

// gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
//переместить потом в либу
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ex_error(int num)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
	//return ;
}

void	line(int x0, int y0, int x1, int y1, t_mlx *mlx, unsigned int color)
{
	int 			x;
	int 			y;
	int 			dx;
	int 			dy;
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
	dy = y1 - y0;
	dx = x1 - x0;
	err = 0;
	mlx->data[y0 * SIZE_X + x0] = 0xffff00;
	while (x <= x1)
	{
		if (flag)
			mlx->data[y * SIZE_X + x] = color;
		else
			mlx->data[x * SIZE_X + y] = color;
		err += abs(dy) * 2;
		if (err > dx)
		{
			y += (y1 > y0 ? 1 : -1);
			err -= dx * 2;
		}
		x++;
	}
}

int		main(int argv, char **argc)
{
	t_mlx	*mlx;
	int 	fd;

	if (argv != 2 || (fd = open(argc[1], O_RDONLY)) <= 0)
		ex_error(1);

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->map = map_read(fd);
	mlx->ptr = mlx_init();

	mlx->win_ptr = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fractol");
	
	mlx->img_ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));


	line(45, 20, 427, 326, mlx, mlx_get_color_value (mlx->ptr, 0x08ffb5));
	line(20,427, 462, 25,  mlx, mlx_get_color_value (mlx->ptr, 0x08f000));
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_loop(mlx->ptr);
}
