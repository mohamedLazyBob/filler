/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:46:49 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 14:55:24 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** ***************************************************************************
*/

int		ft_get_player(int *player)
{
	char	*line;
	int		len;

	line = NULL;
	if (-1 == get_next_line(0, &line))
		return (FALSE);
	len = ft_strlen("$$$ exec p");
	if (ft_strnequ("$$$ exec p", line, len) == FALSE)
	{
		ft_print_error("in [$$$ ...]", line);
		ft_memdel((void**)&line);
		return (FALSE);
	}
	if (ft_isdigit(line[len]) == TRUE)
		*player = ft_atoi(line + len);
	else
	{
		ft_print_error("player number", line);
		ft_memdel((void**)&line);
		return (FALSE);
	}
	if (ft_strequ(line + 11, " : [mzaboub.filler]") == FALSE)
		ft_print_error("player nbr is valid, but player name isn't.", line);
	ft_memdel((void**)&line);
	return (TRUE);
}

/*
** ***************************************************************************
*/

int		ft_check_map(char ***map, int rowes)
{
	int i;
	int j;
	int bol;

	i = 0;
	bol = 0;
	while ((*map)[++i] && (bol == 0))
	{
		j = 4;
		while ((*map)[i][j] && (bol == 0))
		{
			if ((j > rowes + 4) || ((*map)[i][j] != '.' && \
				(*map)[i][j] != '\n' && \
					(*map)[i][j] != 'o' && (*map)[i][j] != 'x' && \
					(*map)[i][j] != 'O' && (*map)[i][j] != 'X'))
				bol = 1;
			j++;
		}
		if (j != (rowes + 4))
			bol = 1;
	}
	if (bol == 0)
		return (TRUE);
	ft_memdel2d(map);
	return (FALSE);
}

/*
** ***************************************************************************
*/

int		ft_get_the_map(char ***map)
{
	int		cols;
	int		rows;
	int		i;

	if (ft_get_indexs("Plateau", &rows, &cols) == FALSE)
		return (FALSE);
	if (!(*map = (char**)malloc(sizeof(char*) * (rows + 2))))
	{
		ft_print_error("map isn't allocated : ", NULL);
		return (FALSE);
	}
	i = -1;
	while (++i < (rows + 1))
		get_next_line(0, *map + i);
	(*map)[i] = NULL;
	return (ft_check_map(map, cols));
}

/*
** ***************************************************************************
*/

void	ft_parse_input(int player)
{
	char	**map;
	char	**token;
	t_point	pad;
	t_point	score;

	while (TRUE)
	{
		if (FALSE == ft_get_the_map(&map))
			return ;
		if (FALSE == ft_get_the_token(&token))
			return ;
		ft_shift_token(token, &pad);
		ft_drow_heatmap(map, player);
		score = ft_resolve(map, token);
		if (score.i != -1337 && score.j != -1337)
			ft_printf("%d %d\n", score.i - pad.i - 1, score.j - pad.j - 4);
		ft_memdel2d(&map);
		ft_memdel2d(&token);
		if (score.i == -1337 && score.j == -1337)
			break ;
	}
	ft_printf("%d %d\n", 0, 0);
}

/*
** ***************************************************************************
*/

int		main(void)
{
	int	player;

	if (TRUE == ft_get_player(&player))
		ft_parse_input(player);
	else
		write(2, "Player isn't Valid.\n", 20);
	return (0);
}

/*
** ***************************************************************************
*/
