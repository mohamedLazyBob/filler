/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:46:49 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/04 02:44:40 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	print_map(int fd, int x, int y, char **map)
{
	int i = 0;
	dprintf(fd, "x == %d,\ty == %d\n-------\n", x, y);	
	while (i < (1 + x))
	{
		dprintf(fd, "%s\n", map[i]);
		i++;
	}
}

void	ft_get_player(int *player)
{
	char	*line;
	int		i = 0;

	get_next_line(0, &line);
	if (line[10] == '2')
		*player = 2;
	else if (line[10] == '1')
		*player = 1;
	ft_memdel((void**)&line);
}

void	ft_get_the_map(int fd, char ***map)
{
	char	*line;
	int		x, y, i;

	get_next_line(0, &line);
	x = ft_atoi(line + 8);
	i = 9;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	y = ft_atoi(line + i);
	if (!(*map = (char**)malloc(sizeof(char*) * (x + 2))))
	{
		perror("map isn't allocated : ");
		return ;
	}
	(*map)[x + 1] = NULL;
	i = 0;
	while (i < (1 + x))
	{
		get_next_line(0, *map + i);
		i++;	
	}
	/************ allocation/reading of map is done now *****************/
//	print_map(fd, x, y, *map);
}
void	ft_parse_input(int fd)
{
	int		i = 0;
	int 	bol;
	int		player;
	char	**map;

	ft_get_player(&player);
	dprintf(fd, "[player number is %d]\n", player);
	bol = 1;
	while (bol == 1)
	{
		ft_get_the_map(fd, &map);
		ft_place_token(map, player, fd);
		bol = 0;
		
//		i = 0;
//		while (map[i])
//			ft_memdel((void**)(map + i));
//		ft_memdel((void***)&map);
	}
}

int		main(void)
{
	int fd;

	fd = open("text", O_WRONLY);
	ft_parse_input(fd);
	return (0);
}
