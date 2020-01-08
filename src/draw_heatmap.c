/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:41:39 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/08 05:20:51 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# define TRUE 1
# define FALSE 0

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

int		place_near2(char **map, char before, char this, int fd)
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
//				if (1 == is_around_other(map, i, j, '1'))
//					return (0);
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

int		ft_drow_heatmap(char **map, char **token, int player, int fd)
{
	int bol;
	int	i;
	int	j;
	int	this;
	int	some_space;
	char	p1, p2;

	if (player == 1) {
		p1 = 'o';	p2 = 'x';
	}
	else {
		p1 = 'x';	p2 = 'o';
	}

	place_near(map, p1, p2, 'A');
	place_near(map, p2, p1, '1');
//	dprintf(fd, "-------------- before heatmap ----\n");
//	print_map(fd, map);
	i = 0;
	this = 'B';
	while (TRUE)
	{
		some_space = place_near2(map, this - 1, this, fd);
		if (some_space == 0)
			break;
		this++;
		i++;
	}
//	dprintf(fd, "-------------- after heatmap ----\n");
//	print_map(fd, map);
	return (bol);
}

/*
** ***************************************************************************
*/

