/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:46:49 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/06 03:38:19 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	print_map(int fd, char **map)
{
	int i = 0;
	dprintf(fd, "--------------------------------\n");
	while (map[i] != NULL)
	{
		dprintf(fd, "%s\t|\n", map[i]);
		i++;
	}
	dprintf(fd, "--------------------------------\n");
}

/*
** ***************************************************************************
*/

int		ft_get_player(int *player, int fd)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = ft_strlen("$$$ exec ");//8
	if (ft_strncmp("$$$ exec ", line, i))
	{
		dprintf(fd, "line == [%s]\n", line);
		return (FALSE);
	}
	i++;
	if (FALSE ==ft_strnequ(line + i, "p", 1))
		*player = ft_atoi(line + i);
	else
	{
		dprintf(fd, "line == [%s]\n", line);
		return (FALSE);
	}
	if (ft_strequ(line + 11, " : [mzaboub.filler]") == 0)
		dprintf(fd, "{red} player nbr is valid, but player name isn't.{eoc}\n");
	ft_memdel((void**)&line);
	return (TRUE);
}

/*
** ***************************************************************************
*/

int		ft_check_map(char ***map)
{
	int i;
	int j;

	i = 1;
	while ((*map)[i])
	{
		j = 4;
		while ((*map)[i][j])
		{
			if ((*map)[i][j] != ' ' && (*map)[i][j] != '.' && (*map)[i][j] != 'o' && \
					(*map)[i][j] != 'x' && (*map)[i][j] != 'O' && (*map)[i][j] != 'X' &&\
				   	(*map)[i][j] != '\n')
			{
			//	ft_memdel2d((void***)map);
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
			if ((*token)[i][j] != ' ' && (*token)[i][j] != '.' && \
					(*token)[i][j] != '*' && (*token)[i][j] != '\n')
			{
			//	ft_memdel2d((void***)token);
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
	char 	**split;
	int		lines, cols, i;

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	if (ft_strequ("Plateau", split[0]) == 0)
		return (FALSE);
	split[2][ft_strlen(split[2]) - 1] = '\0';
	if ((ft_isstrdigit(split[1]) == FALSE) || (ft_isstrdigit(split[2]) == FALSE))
	{
		dprintf(fd, "Plateau line/numbers, ins't valid.\n");
		return (FALSE);
	}
	lines = ft_atoi(split[1]);
//	dprintf(fd, "line == %d.\n", lines);
	cols = ft_atoi(split[2]);
	if (!(*map = (char**)malloc(sizeof(char*) * (lines + 2))))
	{
		perror("map isn't allocated : ");
		return (FALSE);
	}
	i = -1;
	while (++i < (1 + lines))
		get_next_line(0, *map + i);
	(*map)[i] = NULL;
//	print_map(fd, *map);
//	ft_memdel2d((void***)split);
	return (ft_check_map(map));
	return (TRUE);
}

/*
** ***************************************************************************
*/

int		ft_get_the_token(int fd, char ***token)
{
	char	*line;
	char	**split;
	int		lines;
	int		cols;
	int		i;

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	if (ft_strequ("piece", split[0]) == 0)
		return (FALSE);
	if ((ft_isstrdigit(split[1]) == FALSE) || (ft_isstrdigit(split[2]) == FALSE))
	{
		dprintf(fd, "piece line/numbers, ins't valid.\n");
		return (FALSE);
	}
	lines = ft_atoi(split[1]);
	cols = ft_atoi(split[2]);
	if (!(*token = (char**)malloc(sizeof(char*) * (lines + 1))))
	{
		perror("piece isn't allocated : ");
		return (FALSE);
	}
	i = -1;
	while (++i < lines)
		get_next_line(0, *token + i);
	(*token)[i] = NULL;
//	ft_memdel2d((void***)&split);
	return (ft_check_token(token));
}

/*
** ***************************************************************************
*/

void	ft_parse_input(int fd)
{
	int		i = 0;
	int 	bol;
	int		player;
	char	**map;
	char	**token;

	if (FALSE == ft_get_player(&player, fd))
	{
		dprintf(fd, "Player isn't Valid.\n");
		return ;
	}
//	dprintf(fd, "[player number is %d]\n", player);
	bol = 1;
	while (bol == 1)
	{
		if (FALSE == ft_get_the_map(fd, &map))
		{
			dprintf(fd, "Map isn't valid.\n");
			return ;
		}
		print_map(fd, map);
		if (FALSE == ft_get_the_token(fd, &token))
		{
			dprintf(fd, "piece is not Valid.\n");
			//ft_memdel2d((void***)&map);
			return ;
		}
		print_map(fd, token);
		ft_place_token(map, token, player, fd);
		bol = 0;
		i = 0;
		while (map[i])
			ft_memdel((void**)(map + i));
		free(map);
	}
}

/*
** ***************************************************************************
*/


int		main(void)
{
	int fd;

	fd = open("text", O_WRONLY);
	dprintf(fd, "-------------------- start ----------------------\n");
	ft_parse_input(fd);
	close(fd);
	return (0);
}

/*
** ***************************************************************************
*/
