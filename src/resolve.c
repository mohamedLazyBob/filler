/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:41:39 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/04 02:44:38 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# define TRUE 1
# define FALSE 0

int		ft_place_token(char **map, int player, int fd)
{
	int bol;
	int	i;
	int	j;
	int	var;
	int	some_space;
	char	p1, p2;

	i = 0;
	if (player == 1)
	{
		p1 = 'o';
		p2 = 'x';
	}
	else
	{
		p1 = 'x';
		p2 = 'o';
	}
	var = 0;
//	while (TRUE)
//	{
//		some_space = 0;
		i = 1;
		while (map[i] != NULL)
		{
			j = 4;
			while (map[i][j] != '\0')
			{
				if (map[i][j] != 'x' && map[i][j] != 'X' && map[i][j] != 'o' && map[i][j] != 'O')
				{
					map[i][j] = '0';
//					some_space = 1;
				}
				j++;
			}
			i++;
		}
//		if (some_space == 0)
//			break;
//		var++;
//	}
	dprintf(fd, "=========================\n");
	print_map(fd, 15, 17, map);
	return (bol);
}
