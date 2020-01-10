/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:41:39 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 08:35:13 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** ***************************************************************************
*/

int		place_near(char **map, char p1, char p2, char this)
{
	int i;
	int j;
	int ret;

	i = 1;
	ret = 0;
	while (map[i] != NULL)
	{
		j = 4;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != p1 && map[i][j] != ft_toupper(p1) && \
					(map[i][j] == p2 || map[i][j] == ft_toupper(p2)))
			{
				map[i][j] = this;
				ret = 1;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

/*
** ***************************************************************************
*/

void	place_around(char **map, int i, int j, char this)
{
	if (i > 0)
	{
		if ((j > 0) && map[i - 1][j - 1] == '.')
			map[i - 1][j - 1] = this;
		if (map[i - 1][j] == '.')
			map[i - 1][j] = this;
		if (map[i - 1][j + 1] == '.')
			map[i - 1][j + 1] = this;
	}
	if ((j > 0) && map[i][j - 1] == '.')
		map[i][j - 1] = this;
	if (map[i][j + 1] == '.')
		map[i][j + 1] = this;
	if (map[i + 1] != NULL)
	{
		if ((j > 0) && map[i + 1][j - 1] == '.')
			map[i + 1][j - 1] = this;
		if (map[i + 1][j] == '.')
			map[i + 1][j] = this;
		if (map[i + 1][j + 1] == '.')
			map[i + 1][j + 1] = this;
	}
}

/*
** ***************************************************************************
*/

int		is_around_other(char **map, int i, int j, char this)
{
	if (i > 0)
	{
		if ((j > 0) && map[i - 1][j - 1] == this)
			return (1);
		if (map[i - 1][j] == this)
			return (1);
		if (map[i - 1][j + 1] == this)
			return (1);
	}
	if ((j > 0) && map[i][j - 1] == this)
		return (1);
	if (map[i][j + 1] == this)
		return (1);
	if (map[i + 1] != NULL)
	{
		if ((j > 0) && map[i + 1][j - 1] == this)
			return (1);
		if (map[i + 1][j] == this)
			return (1);
		if (map[i + 1][j + 1] == this)
			return (1);
	}
	return (0);
}

/*
** ***************************************************************************
*/

int		place_near2(char **map, char before, char this)
{
	int i;
	int j;
	int ret;

	i = 1;
	ret = 0;
	while (map[i] != NULL)
	{
		j = 4;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == before)
			{
				place_around(map, i, j, this);
				ret = 1;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

/*
** ***************************************************************************
*/

void	ft_drow_heatmap(char **map, int player, int fd)
{
	int		i;
	int		this;
	int		some_space;

	if (player == 1)
	{
		place_near(map, 'x', 'o', -1);
		place_near(map, 'o', 'x', 1);
	}
	else
	{
		place_near(map, 'o', 'x', -1);
		place_near(map, 'x', 'o', 1);
	}
	i = 0;
	this = 2;
	while (TRUE)
	{
		some_space = place_near2(map, this - 1, this);
		if (some_space == 0)
			break ;
		this++;
		i++;
	}
	print_map(fd, map);
}

/*
** ***************************************************************************
*/
