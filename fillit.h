/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:32:36 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/23 19:39:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 4096

char	*fill_map(int splitted, char *block, int i, int *taille);
int		posisvalid(char *block, int i);
int		parser2(char *buf);
int		defparse(char *buf, int comp, int start, int i);
int		exception(int parsed);
int		file_is_valid(char *buf);
int		nbrofpos(char *map, char *block, int *data);
int		check_spaces2(int splitted, char *block, int i, int taille);

int		ft_cube(int nb);
char	**split_block(char *argv);
int		*indata(char c, char *block, char *buf);
int		shame(int comp, char *buf, int *v);
int		*initvar(void);
char	*empty_map(int taille);
int		ft_isin(char c, char *str);
void	resolve(int *parsed, int *data);
int		*initdata(char**blocks);
int		ft_sqrt(int nb);
int		*fillparsed(char**blocks);
char	*filled_map(int *parsed, char *map, int *emplacement, int *data);
void	error();
int		*init_int_tab(int nb);
#endif
