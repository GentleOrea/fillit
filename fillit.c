/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <ygarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:53:45 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/23 19:35:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		*data;
	int		*parsed;
	char	**blocks;

	if (argc == 1)
		ft_putstr_fd("No arguments given", 2);
	if (argc > 2)
		ft_putstr_fd("Too many arguments", 2);
	if (argc != 2)
		return (-1);
	blocks = split_block(argv[1]);
	data = initdata(blocks);
	parsed = fillparsed(blocks);
	resolve(parsed, data);
	return (0);
}

void	error(void)
{
	ft_putendl("error");
	exit(1);
}

int		file_is_valid(char *buf)
{
	int		i;
	int		diese;
	int		co;

	diese = 0;
	i = 0;
	co = 0;
	while (buf[i])
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') ||
				(!((i + 1) % 5) && buf[i] != '\n'))
			error();
		if (buf[i] == '#')
		{
			diese++;
			co = (buf[i + 1] == '#') ? ++co : co;
			co = (buf[i + 5] == '#') ? ++co : co;
		}
		i++;
	}
	if ((diese - 4) || co < 3 || (buf[20] && buf[20] != '\n'))
		error();
	free(buf);
	return (buf[20] ? 1 : 0);
}

int		*fillparsed(char **blocks)
{
	int		*parsed;
	int		i;

	i = 0;
	while (blocks[i])
		i++;
	if (!(parsed = (int*)malloc(i * sizeof(int))))
		return (NULL);
	i = -1;
	while (blocks[++i])
		parsed[i] = parser2(blocks[i]);
	parsed[i] = -42;
	return (parsed);
}

int		ft_cube(int nb)
{
	int		i;

	i = 0;
	while (((i * i) * i) < nb)
		i++;
	return (i);
}
