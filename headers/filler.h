/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:05:46 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/07 09:11:11 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "../libftprintf/headers/ft_printf.h"
#include <time.h>

typedef	struct	s_point
{
	int	i;
	int	j;
}				t_point;

/*		resolve.c	*/

int		is_placeable(char **map, t_point a, char **token, t_point b, int fd);
int		get_point_score(char **map, t_point ij, t_point *pt, char **token, int fd);
t_point	ft_resoleve(char **map, int fd, char **token);



/*		draw_map.c	*/
void	ft_parse_input(int fd);
int 	ft_get_the_map(int fd, char ***map);
int 	ft_get_player(int *player, int fd);
void 	print_map(int fd, char **map);
int     is_around_other(char **map, int i, int j, char this);
int		ft_drow_heatmap(char **map, char **token, int player, int fd);

/*		fortest_funcs.x	*/
void	ft_place_token(int fd, char **map, int i, int j, char **token);

#endif
