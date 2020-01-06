/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:37:31 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/06 03:38:18 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

typedef	struct	s_point
{
	int	i;
	int	j;
}				t_point;

int		get_score(char **map, t_point ij, t_point *pt, char **token);

void	ft_resoleve(char **map, int fd, char **token)
{
	t_point ij;
	t_point a;
	t_point	bestplace;
	int		bestscore;
	int		score;

	ij.i = 0;
	bestscore = 0;
	while (map[ij.i])
	{
		ij.j = 4;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == '5')
			{
				// check the best score to place it in this '5'
				if ((score = get_score(map, ij, &a, token)) > bestscore)
				{
					bestscore = score;
					bestplace = a;
				}
			}
			ij.j++;
		}
		ij.i++;
	}
// by now you should have the bestplce where you can place the token;	
}

int		get_score(char **map, t_point ij, t_point *pt, char **token)
{
	// check all possible combinaisons in this ij;
	
	return (0);
}
