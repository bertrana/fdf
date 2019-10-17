/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:06:15 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/05 17:26:59 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1
# define SIZE_X 1500
# define SIZE_Y 1500

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				size_l;
	int				e;
	int				p_i;
	int				left_right;
	int				up_down;
	int				zoom;
	int				d_z;
	int				**mmap;
	int				map_h;
	int				map_w;
	struct s_mlx	*next;
}					t_mlx;

void				ex_error(int num);
int					find_d_z(int **map, int h, int w);
t_mlx				*ft_init(t_mlx *m, char *name_f);
int					get_next_line(const int fd, char **line);
void				draw_image(t_mlx *m);
void				controls(t_mlx *mlx);
void				check_coord(int *x, int *y, t_mlx *m, int point[2]);

#endif
