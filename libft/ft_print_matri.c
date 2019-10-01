/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:01:04 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/28 13:18:18 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matri(int **matr, int x, int y)
{
	int 	i;
	char	n;

	n = '\n';
	i = 0;
	while (i < y)
	{
		ft_print_massi(matr[i], x);
		i++;
	}
	write(1, &n, 1);
}
