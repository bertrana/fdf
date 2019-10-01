#include "fdf.h"

int 	count_num(char *str)
{
	int len;
	int flag;

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

int 	*str_parser(char *str, int *h)
{
	int			*mass;
	int 		tmp;

	tmp = count_num(str);
	if (*h != 0 && *h != tmp)
		ex_error(3);
	else if (*h == 0)
		*h = tmp;
	mass = (int *)malloc(*h * sizeof(int));
	//if (!mass)
	//	ex_error(1);
	tmp = 0;
	while (tmp < *h && *str)
	{
		mass[tmp] = ft_atoi(str);
		str = ft_strchr(str, ' ') + 1;
		tmp++;
	}
	return (mass);
}

void	map_read(t_mlx *m, char *name_f)
{
	int		fd;
	char 	*str;
	int 	tmp;
	int		i;

	i = 0;
	if ((fd = open(name_f, O_RDONLY)) <= 0)
		ex_error(-1);
	while((tmp = get_next_line(fd, &str)) > 0)
	{
		m->map[i] = str_parser(str, &(m->map_h));
		free(str);
		i++;
	}
	tmp < 0 ? ex_error(-1) : i++;
}