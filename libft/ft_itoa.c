/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:59:34 by yjohns            #+#    #+#             */
/*   Updated: 2019/06/30 19:48:46 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(int n)
{
	int		len;
	int		minus;

	minus = 0;
	len = 1;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	while ((n /= 10) > 0)
		len++;
	return ((minus) ? len + 1 : len);
}

static int		ft_get_tens(int n)
{
	int tens;

	tens = 1;
	while ((n /= 10) > 0)
		tens *= 10;
	return (tens);
}

char			*ft_itoa(int n)
{
	int		tens;
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = ft_strnew(ft_get_len(n))))
		return (NULL);
	if (n < 0)
	{
		ptr[i++] = '-';
		if (n == -2147483648)
			ptr[i++] = '2';
		if (n == -2147483648)
			n = -147483648;
		n = -n;
	}
	tens = ft_get_tens(n);
	while (tens)
	{
		ptr[i++] = ((char)(n / tens) + 48);
		n %= tens;
		tens /= 10;
	}
	ptr[i] = '\0';
	return (ptr);
}
