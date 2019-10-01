#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "../libft/libft.h"

#define BUFF_SIZE 1
#define SIZE_X 500
#define SIZE_Y 500

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;

	int 		    bpp;
	int 		    size_l;
	int				e;

	int 			**map;
	int 			map_h; //x
	int 			map_w; //y

	struct s_mlx		*next;
}					t_mlx;


void	ex_error(int num);
void	line(int x0, int y0, int x1, int y1, t_mlx *mlx);
t_mlx	*ft_init(t_mlx *m, char *name_f);
void 	ft_count(int *h, int *w, char *name_f);
void	map_read(t_mlx *m, char *name_f);
int		get_next_line(const int fd, char **line);

#endif
