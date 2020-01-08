/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fortest_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 05:51:40 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/07 09:11:33 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_token(int fd, char **map, int i, int j, char **token)
{
	int	a, b;

	a = 0;
	dprintf(fd, "============= before placing the token ======\n");
	dprintf(fd, "============= i %d, j %d ======\n", i, j);
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
	dprintf(fd, "============= after placing the token ======\n");
	print_map(fd, map);
}
