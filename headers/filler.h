/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:05:46 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/09 09:25:53 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "../libftprintf/headers/ft_printf.h"
#include <fcntl.h>
#include <time.h>
# define TRUE 1
# define FALSE 0

typedef	struct	s_point
{
	int	i;
	int	j;
}				t_point;

/*		resolve.c	*/

int		is_placeable(char **map, t_point a, char **token, t_point b, int fd);
int		get_point_score(char **map, t_point ij, t_point *pt, char **token, int fd);
t_point	ft_resoleve(char **map, int fd, char **token);



/*		draw_heatmap.c	*/
int		place_near(char **map, char p1, char p2, char this);
void	place_around(char **map, int i, int j, char this);
int		is_around_other(char **map, int i, int j, char this);
int		place_near2(char **map, char before, char this);
void	ft_drow_heatmap(char **map, int player, int fd);


/*		parser.c		*/
void	ft_parse_input(int fd, int player);
int 	ft_get_the_map(int fd, char ***map);
int 	ft_get_player(int *player, int fd);
void 	print_map(int fd, char **map);

/*		fortest_funcs.x	*/
void	ft_place_token(int fd, char **map, int i, int j, char **token);

#endif
