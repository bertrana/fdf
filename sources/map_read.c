#include "fdf.h"

int 	validation(char **str)
{
	return (0);
}

char 	**map_read(t_mlx *m, char *name_f)
{
	int		fd;
	char

	if ((fd = open(name_f, O_RDONLY)) <= 0)
		ex_error(2);
}