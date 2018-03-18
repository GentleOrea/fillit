/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:42:53 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/11 13:14:20 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_isinf(size_t val, size_t vul)
{
	return ((int)(val < vul));
}

int	ft_issup(size_t val, size_t vul)
{
	return ((int)(val > vul));
}

int	ft_iseq(size_t val, size_t vul)
{
	return ((int)(val == vul));
}

int	ft_isin(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c);
}
