/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:49:25 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/23 19:38:38 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**split_block(char *argv)
{
	int		ret;
	char	**tab;
	char	buf[BUFF_SIZE + 1];

	if ((ret = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl("Failed to open the file");
		exit(1);
	}
	buf[read(ret, buf, BUFF_SIZE)] = '\0';
	ret = 0;
	while (file_is_valid(ft_strsub(buf, (unsigned int)ret * 21, 21)))
		ret++;
	if (!(tab = (char**)malloc((unsigned long)(ret + 2) * sizeof(char*))))
		return (NULL);
	tab[++ret] = NULL;
	while (ret--)
		tab[ret] = ft_strsub(buf, (unsigned int)ret * 21, 20);
	ret = 0;
	while (tab[ret])
		ret++;
	if (ret > 26)
		error();
	return (tab);
}

int				posisvalid(char *block, int i)
{
	int		cp;

	cp = 1;
	if (!block[i] || block[i] != '.')
		cp = -42;
	return (cp);
}

int				check_spaces2(int parsed, char *block, int i, int taille)
{
	int		mod;
	int		begin;
	int		ligne;
	int		valid;

	mod = 1000;
	begin = i;
	ligne = 1;
	valid = posisvalid(block, i);
	while (block[i] && (mod /= 10) > 0)
	{
		if (block[++i] && (parsed % (mod * 10) / mod) < 3)
			valid += posisvalid(block, i);
		else
		{
			i = begin + ((taille + 1) * ligne) +
					(parsed % (mod * 10) / mod) - 3 - (parsed / 1000);
			if (i < (taille * (taille + 1)) && ligne++)
				valid += posisvalid(block, i);
			else
				return (0);
		}
	}
	return (valid < 4 ? 0 : 1);
}
