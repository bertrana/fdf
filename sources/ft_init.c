/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 02:59:13 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/06 14:52:05 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_num(char *str)
{
	int		len;
	int		flag;

	flag = 0;
	len = 0;
	while (*str)
	{
		while (ft_isdigit(*str) || *str == '+' || *str == '-')
		{
			if (flag == 0)
			{
				len++;
				flag = (ft_atoi(str) == 0 ? 1 : 2);
			}
			str++;
		}
		if (!(ft_isdigit(*str) || *str == '+' || *str == '-'))
			flag = 0;
		if (!(*str))
			break ;
		str++;
	}
	return (len);
}

static int	*str_parser(char *str, int *h)
{
	static int	i = 0;
	int			*mass;
	int			tmp;

	tmp = count_num(str);
	if (*h != 0 && *h != tmp)
		ex_error(3);
	else if (*h == 0)
		*h = tmp;
	mass = (int *)malloc(*h * sizeof(int));
	tmp = 0;
	while (tmp < *h && *str)
	{
		mass[tmp] = ft_atoi(str);
		str++;
		str = ft_strchr(str, ' ') + 1;
		tmp++;
	}
	i++;
	return (mass);
}

static void	map_read(t_mlx *m, char *name_f)
{
	int		fd;
	char	*str;
	int		tmp;
	int		i;

	i = 0;
	if ((fd = open(name_f, O_RDONLY)) <= 0)
		ex_error(-1);
	while ((tmp = get_next_line(fd, &str)) > 0)
	{
		m->mmap[i] = str_parser(str, &(m->map_h));
		free(str);
		i++;
	}
	tmp < 0 ? ex_error(-1) : i++;
}

static void	ft_count(int *h, int *w, char *name_f)
{
	int		fd;
	char	*str;
	int		tmp;

	fd = open(name_f, O_RDONLY);
	fd < 0 ? ex_error(-1) : (*w = 0);
	while ((tmp = get_next_line(fd, &str)) > 0)
	{
		*h = 0;
		while (str[*h])
		{
			if (str[*h] != ' ' && !ft_isdigit(str[*h]) && str[*h] != '-' &&
				str[*h] != '+')
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

t_mlx		*ft_init(t_mlx *m, char *name_f)
{
	char	*tmp;
	int		a;
	int		b;

	ft_count(&(m->map_h), &(m->map_w), name_f);
	m->ptr = mlx_init();
	m->mmap = (int **)malloc(sizeof(int *) * m->map_w);
	map_read(m, name_f);
	m->d_z = find_d_z(m->mmap, m->map_h, m->map_w);
	m->win_ptr = mlx_new_window(m->ptr, SIZE_X, SIZE_Y, "fdf");
	m->img_ptr = mlx_new_image(m->ptr, SIZE_X, SIZE_Y);
	tmp = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->size_l), &(m->e));
	m->data = (int *)tmp;
	m->p_i = 0;
	m->left_right = 0;
	m->up_down = 0;
	a = (SIZE_X / m->map_h) / 2;
	b = (SIZE_Y / (m->map_w > (m->d_z) ? m->map_w : (m->d_z))) / 2;
	m->zoom = a > b ? b : a;
	return (m);
}
