/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:52:21 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/03 17:49:10 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		err_e()
{
	write(2, "156Can't work with file\n", ft_strlen("156Can't work with file\n"));
	exit(EXIT_FAILURE);
}

static int	find_number(const char **str)
{
	int	min;

	min = 1;
	while ((**str == ' ' || (**str < 14 && **str > 8)) && **str)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			min = -1;
		(*str)++;
	}
	return (min);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	min;

	min = find_number(&str);
	i = 0;
	while (ft_isdigit(*str) && *str)
	{
		i = i * 10 + (*str - '0') * min;
		str++;
		if (*str && !(ft_isdigit(*str)) && (*str != ' '))
			err_e();
		if (*str && ((i * 10 < -2147483648 && *str == '9') ||
				(i * 10 > 2147483647 && (*str == '8' || *str == '9'))))
			err_e();
	}
	return (i);
}
