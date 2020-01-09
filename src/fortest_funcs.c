/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fortest_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 05:51:40 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/09 04:15:14 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_token(int fd, char **map, int i, int j, char **token)
{
	int	a, b;

	a = 0;
	print_map(fd, map);
	while (token[a] && map[a + i])
	{
		b = 0;
		while (token[a][b] && map[a + i][b + j])
		{
			if (token[a][b] == '*' && map[a + i][b + j])
			{
				map[a + i][b + j] = '*';
			}
			b++;
		}
		a++;
	}
	print_map(fd, map);
}
