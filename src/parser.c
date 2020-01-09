/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:46:49 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/09 11:17:03 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(int fd, char **map)
{
	int i;
	int j;

	i = 1;
	ft_putstr_fd("--------------------------------\n", fd);
	dprintf(fd, "%s\n", map[0]);
	while (map[i] != NULL)
	{
		//ft_putstr_fd(map[i], fd);
		dprintf(fd, "%.3d ", i);
		j = 4;
		while (map[i][j])
		{
			dprintf(fd, "%2d, ", map[i][j]);
			j++;
		}
		dprintf(fd, "|\n");
		i++;
	}
	ft_putstr_fd("--------------------------------\n", fd);
}

/*
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

int		ft_get_player(int *player, int fd)
{
	char	*line;
	int		len;

	get_next_line(0, &line);
	len = ft_strlen("$$$ exec p");
	if (ft_strnequ("$$$ exec p", line, len) == FALSE)
	{
		ft_print_error("in [$$$ ...]", line, fd);
		ft_memdel((void**)&line);
		return (FALSE);
	}
	if (ft_isdigit(line[len]) == TRUE)
		*player = ft_atoi(line + len);
	else
	{
		ft_print_error("player number", line, fd);
		ft_memdel((void**)&line);
		return (FALSE);
	}
	if (ft_strequ(line + 11, " : [mzaboub.filler]") == FALSE)
		ft_print_error("player nbr is valid, but player name isn't.", line, fd);
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

	i = 1;
	while ((*map)[i])
	{
		j = 4;
		while ((*map)[i][j])
		{
			if (j > rowes + 4)
				return (FALSE);
			if ((*map)[i][j] != '.' && \
					(*map)[i][j] != 'o' && (*map)[i][j] != 'x' && \
					(*map)[i][j] != 'O' && (*map)[i][j] != 'X' && \
					(*map)[i][j] != '\n')
			{
				ft_memdel2d(map);
				return (FALSE);
			}
			j++;
		}
		if (j != (rowes + 4))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
** ***************************************************************************
*/

int		ft_check_token(char ***token)
{
	int i;
	int j;

	i = 0;
	while ((*token)[i])
	{
		j = 0;
		while ((*token)[i][j])
		{
			if ((*token)[i][j] != '.' && \
					(*token)[i][j] != '*' && (*token)[i][j] != '\n')
			{
				ft_memdel2d(token);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
** ***************************************************************************
*/

int		ft_get_the_map(int fd, char ***map)
{
	char	*line;
	char	**splt;
	int		lines;
	int		i;

	get_next_line(0, &line);
	splt = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	if (ft_strequ("Plateau", splt[0]) == FALSE)
	{
		ft_memdel2d(&splt);
		return (FALSE);
	}
	splt[2][ft_strlen(splt[2]) - 1] = '\0';
	if ((ft_isstrdigit(splt[1]) == FALSE) || (ft_isstrdigit(splt[2]) == FALSE))
	{
		ft_memdel2d(&splt);
		ft_print_error("Plateau line/numbers, ins't valid.\n", NULL, fd);
		return (FALSE);
	}
	lines = ft_atoi(splt[1]);
	int rowes = ft_atoi(splt[2]);
	if (!(*map = (char**)malloc(sizeof(char*) * (lines + 2))))
	{
		ft_memdel2d(&splt);
		ft_print_error("map isn't allocated : ", NULL, fd);
		return (FALSE);
	}
	i = -1;
	while (++i < (lines + 1))
		get_next_line(0, *map + i);
	(*map)[i] = NULL;
	ft_memdel2d(&splt);
	print_map(fd, *map);
	return (ft_check_map(map, rowes));
}

/*
** ***************************************************************************
*/

int		ft_get_the_token(int fd, char ***token)
{
	char	*line;
	char	**splt;
	int		lines;
	int		cols;
	int		i;

	get_next_line(0, &line);
	splt = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	if (ft_strequ("Piece", splt[0]) == FALSE)
	{
		ft_print_error("token : ", splt[0], fd);
		ft_putstr_fd(line, fd);
		ft_memdel2d(&splt);
		return (FALSE);
	}
	splt[2][ft_strlen(splt[2]) - 1] = '\0';
	if ((ft_isstrdigit(splt[1]) == FALSE) || (ft_isstrdigit(splt[2]) == FALSE))
	{
		ft_print_error("piece line/numbers, ins't valid.\n", NULL, fd);
		ft_memdel2d(&splt);
		return (FALSE);
	}
	lines = ft_atoi(splt[1]);
	if (!(*token = (char**)malloc(sizeof(char*) * (lines + 1))))
	{
		ft_memdel2d(&splt);
		perror("piece isn't allocated ");
		return (FALSE);
	}
	i = -1;
	while (++i < lines)
		get_next_line(0, *token + i);
	(*token)[i] = NULL;
	ft_memdel2d(&splt);
	return (ft_check_token(token));
}

/*
** ***************************************************************************
*/

static	void	ft_delet_pad(char **token, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == '*')
			{
				token[i][j] = '.';
				token[i - row][j - col] = '*';
			}
			j++;
		}
		i++;
	}
}

void	ft_shift_token(char **token, t_point *pad)
{
	int	i;
	int	j;

	pad->i = INT_MAX;
	pad->j = INT_MAX;
	i = -1;
	while (token[++i])
	{
		j = -1;
		while (token[i][++j])
		{
			if (token[i][j] == '*' && (i < pad->i))
				pad->i = i;
			if (token[i][j] == '*' && (j < pad->j))
				pad->j = j;
		}
	}
	ft_delet_pad(token, pad->i, pad->j);
}

/*
** ***************************************************************************
*/

void	ft_parse_input(int fd, int player)
{
	char	**map;
	char	**token;
	t_point	pad;
	t_point	score;

	

	while (TRUE)
	{
		if (FALSE == ft_get_the_map(fd, &map))
			return ;
		ft_putstr_fd("-------------------- HERE ----------------------\n", fd);
		print_map(fd, map);
		if (FALSE == ft_get_the_token(fd, &token))
			return ;
		ft_shift_token(token, &pad);
		ft_drow_heatmap(map, player, fd);
		score = ft_resoleve(map, fd, token);
		if (score.i != -1337 && score.j != -1337)
			ft_printf("%d %d\n", score.i - pad.i - 1, score.j - pad.j - 4);
		ft_memdel2d(&map);
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
	int fd;
	int	player;

	fd = open("text", O_WRONLY);
	ft_putstr_fd("-------------------- start ----------------------\n", fd);
	if (TRUE == ft_get_player(&player, fd))
		ft_parse_input(fd, player);
	else
		write(fd, "Player isn't Valid.\n", 20);
	ft_putstr_fd("--------------------  end  ----------------------\n", fd);
	close(fd);
	return (0);
}

/*
** ***************************************************************************
*/
