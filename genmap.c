/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:52:11 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/23 19:37:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*empty_map(int taille)
{
	int		i;
	int		size;
	int		div;
	char	*map;

	i = 0;
	size = 0;
	div = 0;
	size = taille * (taille + 1);
	if (!(map = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size)
	{
		if (i && !((i + 1) % (taille + 1)))
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[--i] = '\0';
	return (map);
}
