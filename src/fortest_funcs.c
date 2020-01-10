/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fortest_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 05:51:40 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 05:35:32 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** ***************************************************************************
*/

void	print_map(int fd, char **map)
{
	int i;
	int j;

	i = 1;
	ft_putstr_fd("--------------------------------\n", fd);
	while (map[i] != NULL)
	{
		j = 4;
		while (map[i][j])
		{
			ft_putnbr_fd(map[i][j], fd);
			write(fd, ", ", 2);
			j++;
		}
		ft_putstr_fd("|\n", fd);
		i++;
	}
	ft_putstr_fd("--------------------------------\n", fd);
}

/*
** ***************************************************************************
**
**
**   void	ft_place_token(int fd, char **map, int i, int j, char **token)
**   {
**   	int	a, b;
**
**   	a = 0;
**   	print_map(fd, map);
**   	while (token[a] && map[a + i])
**   	{
**   		b = 0;
**   		while (token[a][b] && map[a + i][b + j])
**   		{
**   			if (token[a][b] == '*' && map[a + i][b + j])
**   			{
**   				map[a + i][b + j] = '*';
**   			}
**   			b++;
**   		}
**   		a++;
**   	}
**   	print_map(fd, map);
**   }
**
**
** ***************************************************************************
*/

void	ft_print_error(char *str, char *line, int fd)
{
	ft_putstr_fd("============ ERROR ============\n", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(" == [", fd);
	ft_putstr_fd(line, fd);
	ft_putstr_fd("]\n", fd);
}

/*
** ***************************************************************************
*/
