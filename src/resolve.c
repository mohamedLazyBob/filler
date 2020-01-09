/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:37:31 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/09 09:59:15 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	ft_resoleve(char **map, int fd, char **token)
{
	t_point ij;
	t_point pt_bestscr;
	t_point	bestplace;
	int		bestscore;
	int		score;

	ij.i = 1;
	bestscore = INT_MAX;
	bestplace.i = -1337;
	bestplace.j = -1337;
	dprintf(fd, "=============== this is the token : \n");
	print_map(fd, token);
	while (map[ij.i])
	{
		ij.j = 4;
		while (map[ij.i][ij.j])
		{
			if (map[ij.i][ij.j] == -1)
			{
				// check the best score to place it in this -1
				if ((score = get_point_score(map, ij, &pt_bestscr, token, fd)) < bestscore)
				{
					bestscore = score;
					bestplace.i = pt_bestscr.i;
					bestplace.j = pt_bestscr.j;
				}
			}
			ij.j++;
		}
		ij.i++;
	}
// by now you should have the bestplce where you can place the token;	
	return (bestplace);
}

int		get_point_score(char **map, t_point ij, t_point *pos, char **token, int fd)
{
	// check all possible combinaisons in this ij;
	t_point xy;
	int		ret;
	int		score;

	xy.i = 0;
	score = INT_MAX;
	while (token[xy.i])
	{
		xy.j = 0;
		while (token[xy.i][xy.j])
		{
			ret = is_placeable(map, ij, token, xy, fd);
			if ((ret != -1) && (ret <= score))
			{
				score = ret;	
				pos->i = ij.i - xy.i;
				pos->j = ij.j - xy.j;
				dprintf(fd, "----------------- valid score : %d.\tpos.i= %d;\tpos.j = %d;\n", score, pos->i, pos->j);
			}
			xy.j++;
		}
		xy.i++;
	}
	return (score);
}

int		is_placeable(char **map, t_point a, char **token, t_point b, int fd)
{
	int		row;
	int		col;
	int		bol;
	int		score;
	t_point tok;
	
	row = a.i - b.i;
	if (row < 0)
		return (-1);
	tok.i = 0;
	score = 0;
	bol = 0;
	while (token[tok.i] && map[row])
	{
		tok.j = 0;
		col = a.j - b.j;
		while (token[tok.i][tok.j])
		{
			if (token[tok.i][tok.j] == '*')
			{
				if (row < 1 || col < 4 || (map[row][col] == '\0') || map[row][col] == 1)//the original pading of the map
					return (-1);
				if (map[row][col] != -1)
					score += map[row][col];
				else if ((map[row][col] == -1) && (bol == 0))
				{
					score += (int)map[row][col];
					bol = 1;
				}
				else if ((map[row][col] == -1) && (bol == 1))
					return (-1);
			}
			tok.j++;
			col++;
		}
		tok.i++;
		row++;
	}
	if (token[tok.i] && !map[row])
		return (-1);
	if (bol == 0)
		return (-1);
	return (score);
}
