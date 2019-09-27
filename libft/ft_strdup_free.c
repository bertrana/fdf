/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:40:59 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/04 04:24:03 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdup_free(char **s, char *arg)
{
	char	*tmp;

	tmp = *s;
	tmp = ft_strdup(arg);
	printf("%s - t\n", tmp);
	*s = tmp;
	free(tmp);
}
