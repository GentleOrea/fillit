/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:34:00 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/23 19:29:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		defparse(char *buf, int comp, int start, int i)
{
	int cases;
	int temp;

	temp = 0;
	cases = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	while (buf[i + cases] && ft_isin(buf[i + cases], "\n."))
		cases++;
	if (!buf[i + cases])
		return (comp * 10);
	cases = cases % 5;
	if (cases < start)
	{
		temp = start - cases;
		cases = 3;
	}
	else
		cases = cases - start + 3;
	comp = (comp * 10) + cases + (temp * 10000);
	return (comp);
}

int		shame(int comp, char *buf, int *v)
{
	int i;
	int start;
	int longueur;

	longueur = 0;
	i = 0;
	if (comp == 1330)
		return (1430);
	if (comp == 1303)
	{
		while (buf[longueur] && buf[longueur] != '\n')
			longueur++;
		while (buf[i] && ft_isin(buf[i], "\n."))
			i++;
		start = i;
		i = longueur * (longueur + 1);
		while (ft_isin(buf[i], "\n."))
			i--;
		if (i % (longueur + 1) == start % (longueur + 1))
			comp = 1304;
	}
	free(v);
	return (comp);
}

int		*initvar(void)
{
	int *data;

	if (!(data = (int*)malloc(3 * sizeof(int))))
		return (NULL);
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	return (data);
}

int		parser2(char *buf)
{
	int *v;
	int i;
	int di;

	v = initvar();
	i = 0;
	di = 1;
	while (ft_isin(buf[i], "\n."))
		i++;
	v[2] = (i + 1) % 5;
	while (di < 4)
	{
		if (!ft_isin(buf[i], "\n.") && !ft_isin(buf[i + 1], "\n.") && (++di))
			v[0] *= 10;
		else if (!ft_isin(buf[i], "\n.") &&
				defparse(buf, v[0], v[2], i) >= 10000 && (++di))
		{
			v[1] = defparse(buf, v[0], v[2], i) / 10000;
			v[0] = defparse(buf, v[0], v[2], i) % 10000;
		}
		else if (!ft_isin(buf[i], "\n.") && (++di))
			v[0] = defparse(buf, v[0], v[2], i);
		i++;
	}
	return (shame(v[0] + (v[1] * 1000), buf, v));
}

char	*fill_map(int parsed, char *block, int i, int *taille)
{
	int		mod;
	int		begin;
	int		ligne;

	mod = 1000;
	ligne = 1;
	block[i] = (char)taille[0];
	begin = i;
	while ((mod /= 10) > 0)
	{
		if ((parsed % (mod * 10) / mod) < 3)
		{
			i++;
			block[i] = (char)taille[0];
		}
		else
		{
			i = begin + ((taille[1] + 1) * ligne) + (parsed % (mod * 10) / mod)
				- 3 - (parsed / 1000);
			block[i] = (char)taille[0];
			ligne++;
		}
	}
	return (block);
}
