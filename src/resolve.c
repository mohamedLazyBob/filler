/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:37:31 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 08:52:05 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** ***************************************************************************
*/

t_point	ft_resolve(char **map, char **token)
{
	t_point ij;
	t_point pt;
	t_point	bestplace;
	int		bestscore;
	int		score;

	bestscore = INT_MAX;
	bestplace.i = -1337;
	bestplace.j = -1337;
	ij.i = 0;
	while (map[++ij.i])
	{
		ij.j = 4;
		while (map[ij.i][ij.j])
		{
			if ((map[ij.i][ij.j] == -1) && \
				((score = get_point_score(map, ij, &pt, token)) < bestscore))
			{
				bestscore = score;
				bestplace = pt;
			}
			ij.j++;
		}
	}
	return (bestplace);
}

/*
** ***************************************************************************
*/

int		get_point_score(char **map, t_point ij, t_point *pos, char **token)
{
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
			ret = is_placeable(map, ij, token, xy);
			if ((ret != -1) && (ret <= score))
			{
				score = ret;
				pos->i = ij.i - xy.i;
				pos->j = ij.j - xy.j;
			}
			xy.j++;
		}
		xy.i++;
	}
	return (score);
}

/*
** ***************************************************************************
*/

int		ft_get(char tok, char **map, t_point idx, int *bol)
{
	int	ret;

	ret = 0;
	if (tok == '*')
	{
		if ((idx.i < 1) || (idx.j < 4) || (map[idx.i][idx.j] == '\0') || \
			(map[idx.i][idx.j] == 1) || \
			((map[idx.i][idx.j] == -1) && (*bol == 1)))
			ret = -1337;
		else if (map[idx.i][idx.j] != -1)
			ret = map[idx.i][idx.j];
		else if ((map[idx.i][idx.j] == -1) && (*bol == 0))
		{
			ret = (int)map[idx.i][idx.j];
			*bol = 1;
		}
	}
	return (ret);
}

/*
** ***************************************************************************
**  v[0] == score
**	v[1] == bol
*/

int		is_placeable(char **map, t_point a, char **token, t_point b)
{
	t_point	idx;
	t_point tok;
	int		ret;
	int		v[2];

	if ((idx.i = a.i - b.i - 1) <= 0)
		return (-1);
	tok.i = -1;
	v[0] = 0;
	v[1] = 0;
	while (token[++tok.i] && map[++idx.i])
	{
		tok.j = 0;
		idx.j = a.j - b.j;
		while (token[tok.i][tok.j])
		{
			if ((ret = ft_get(token[tok.i][tok.j++], map, idx, &v[1])) == -1337)
				return (-1);
			v[0] += ret;
			idx.j++;
		}
	}
	if ((token[tok.i] && !map[idx.i]) || (v[1] == 0))
		return (-1);
	return (v[0]);
}

/*
** ***************************************************************************
*/
