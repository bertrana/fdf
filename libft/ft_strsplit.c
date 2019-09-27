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

static int		cw(char const *s, char c)
{
	int counter;
	int in_word;
	int i;

	counter = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			in_word = 0;
		}
		if (s[i] && s[i] != c && in_word == 0)
		{
			in_word = 1;
			counter++;
			i++;
		}
		else
			i++;
	}
	return (counter);
}

static int		lword(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || ((res = (char**)malloc(sizeof(*res) * cw(s, c) + 1)) == NULL))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i])
		{
			if ((res[j] = (char*)malloc(sizeof(char) * lword(s, i, c))) == NULL)
				return (NULL);
			k = 0;
			while (s[i] && s[i] != c)
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
