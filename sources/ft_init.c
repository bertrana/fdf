#include "fdf.h"

void 	ft_count(int *h, int *w, char *name_f)
{
	int 	fd;
	char	*str;
	int 	tmp;

	fd = open(name_f, O_RDONLY);
	fd < 0 ? ex_error(-1) : (*w = 0);
	while ((tmp = get_next_line(fd, &str)) > 0)
	{
		*h = 0;
		while(str[*h])
		{
			if ((str[*h] == ' ' && !ft_isdigit(str[*h - 1])) ||
				(str[*h] != ' ' && !ft_isdigit(str[*h]) && str[*h] != '-' &&
				 str[*h] != '+'))
				ex_error(3);
			(*h)++;
		}
		free(str);
		(*w)++;
	}
	*h = 0;
	if (tmp < 0)
		ex_error(-1);
	close(fd);
}

t_mlx	*ft_init(t_mlx *m, char *name_f)
{
	char	*tmp;

	m->ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->ptr, SIZE_X, SIZE_Y, "fdf");
	m->img_ptr = mlx_new_image(m->ptr, SIZE_X, SIZE_Y);
	tmp = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->size_l), &(m->e));
	m->data = (int *)tmp;

	ft_count(&(m->map_h),&(m->map_w), name_f);
	m->map = (int **)malloc(sizeof(int *) * m->map_w);
	map_read(m, name_f);
	return (m);
}