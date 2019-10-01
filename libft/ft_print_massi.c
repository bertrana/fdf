/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_massi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:03:53 by yjohns            #+#    #+#             */
/*   Updated: 2019/10/02 01:44:26 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_massi(int *mass, int x)
{
	int 	j;
	char	n;

	n = '\n';
	j = 0;
	while (j < x)
	{
		ft_putnbr(mass[j]);
		ft_putchar(' ');
		j++;
	}
	write(1, &n, 1);
}
