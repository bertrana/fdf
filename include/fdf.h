#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

//typedef	struct		s_map
//{
//	int 			x;
//	int 			y;
//	int 			z;
//	struct s_map	*next;
//}					t_map;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;

	int 		    bits_per_pixel;
	int 		    size_line;
	int				endian;

	char 			**map;

//	t_map			*map;
	struct s_mlx		*next;
}					t_mlx;

char 	**map_read(int fd);

#endif
