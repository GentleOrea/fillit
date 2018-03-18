/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:45:22 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/23 19:37:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*filled_map(int *parsed, char *map, int *emplacement, int *data)
{
	int		x;

	x = -1;
	if (map)
		ft_strdel(&map);
	map = empty_map(data[1]);
	while (++x < data[3])
	{
		data[0] = 'A' + x;
		map = fill_map(parsed[x], map, emplacement[x], data);
	}
	return (map);
}

void		resetxy(int *emplacement, int piece)
{
	int i;

	i = 0;
	while (i < piece)
		emplacement[i++] = 0;
}

int			*initdata(char **blocks)
{
	int		*data;
	int		i;

	i = 0;
	if (!(data = (int*)malloc(4 * sizeof(int))))
		return (NULL);
	data[0] = 0;
	while (blocks[i])
		i++;
	data[1] = ft_cube(i * 4);
	data[2] = i;
	data[3] = 0;
	return (data);
}

int			*init_int_tab(int nb)
{
	int	*tab;

	if (!(tab = (int*)malloc(nb * sizeof(int))))
		return (NULL);
	resetxy(tab, nb);
	return (tab);
}

void		resolve(int *parsed, int *data)
{
	int		*emplacement;
	int		begin;
	char	*map;

	emplacement = init_int_tab(data[2]);
	map = (char*)malloc(1);
	while (data[3] < data[2])
	{
		if (emplacement[0] >= (data[1] * data[1] + 1) && data[1]++)
			resetxy(emplacement, data[2]);
		begin = emplacement[data[3]];
		map = filled_map(parsed, map, emplacement, data);
		if (emplacement[data[3]] >= (data[1] * (data[1] + 1)) && data[3] < 1)
			emplacement[data[3]]++;
		if (emplacement[data[3]] >= (data[1] * (data[1] + 1)))
			emplacement[data[3]--] = 0;
		while (map[begin] && (map[begin] != '.' || (map[begin] == '.'
				&& !check_spaces2(parsed[data[3]], map, begin, data[1]))))
			begin++;
		if (map[begin])
			emplacement[data[3]++] = begin;
		else
			emplacement[data[3]]++;
	}
	ft_putstr(filled_map(parsed, map, emplacement, data));
}
