
#include "fdf.h"

#define SIZE_X 500
#define SIZE_Y 500

// gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
//переместить потом в либу


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
	write(2, write_err, ft_strlen(write_err));
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

void 	ft_count(int *h, int *w, char *name_f)
{
	int 	fd;
	char	*str;
	int 	tmp;

	fd = open(name_f, O_RDONLY);
	fd < 0 ? ex_error(2) : (*w = 0);
	*h = 0;
	while ((tmp = get_next_line(fd, &str)) > 0)
	{
		if (*w == 0)
		{
			while(str[*h])
			{
				if
			}
		}
		free(str);
		(*w)++;
	}
	if (tmp < 0)
		ex_error(2);
	close(fd);
}

void	ft_init(t_mlx *m, char *name_f)
{
	char	*tmp;

	m->ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->ptr, SIZE_X, SIZE_Y, "fdf");
	m->img_ptr = mlx_new_image(m->ptr, SIZE_X, SIZE_Y);
	tmp = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->size_l), &(m->e));
	m->data = (int *)tmp;
	ft_count(&(m->map_h),&(m->map_w), name_f);
	m->map = map_read(m, name_f);
}

int		main(int argv, char **argc)
{
	t_mlx	*mlx;
	//int 	fd;


	if (argv != 2)
		ex_error(1);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		ex_error(4);
	ft_init(mlx, argc[1]);

	line(30, 30, 80, 80, mlx, 0xFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_loop(mlx->ptr);
}
