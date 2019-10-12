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
#define SIZE_X 1000
#define SIZE_Y 1000

//typedef struct		s_map
//{
//	int 			x1;
//	int 			y1;
//	int 			x2;
//	int             y2;
//	int             dx;
//	int				dy;
//	int 			sx;
//	int 			sy;
//
//	struct s_map	*next;
//}					t_map;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;

	int 		    bpp;
	int 		    size_l;
	int				e;
	int 			p_i;
	int				zoom;
	int 			cen;

//	t_map			*map;
	int 			**mmap;
	int 			map_h; //x
	int 			map_w; //y

	struct s_mlx		*next;
}					t_mlx;


void	ex_error(int num);
//void	line_p(int x0, int y0, int x1, int y1, t_mlx *mlx);
t_mlx	*ft_init(t_mlx *m, char *name_f);
void 	ft_count(int *h, int *w, char *name_f);
void	map_read(t_mlx *m, char *name_f);
int		get_next_line(const int fd, char **line);
void	p_draw_image(t_mlx *m);
void	i_draw_image(t_mlx *m);
void	draw_image(t_mlx *m);
void	controls(t_mlx *mlx);
//int		check_swap(int *x0, int *y0, int *x1, int *y1);
//t_map	*mass_to_struct(t_mlx *mlx);


//int		ft_lstmlen(t_map *lst);

#endif
