/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:05:46 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 09:31:57 by mzaboub          ###   ########.fr       */
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

/*
**	resolve.c
*/

t_point	ft_resolve(char **map, char **token);
int		get_point_score(char **map, t_point ij, \
						t_point *pos, char **token);
int		ft_get(char tok, char **map, t_point idx, int *bol);
int		is_placeable(char **map, t_point a, char **token, t_point b);



/*
**	draw_heatmap.c
*/

int		place_near(char **map, char p1, char p2, char this);
void	place_around(char **map, int i, int j, char this);
int		is_around_other(char **map, int i, int j, char this);
int		place_near2(char **map, char before, char this);
void	ft_drow_heatmap(char **map, int player, int fd);


/*
**	parser.c
**	this is the main
*/

int 	ft_get_player(int *player, int fd);
int		ft_check_map(char ***map, int rowes);
int 	ft_get_the_map(int fd, char ***map);
void	ft_parse_input(int fd, int player);

/*
**	fortest_funcs.x
**	void	ft_place_token(int	fd, char **map, int i, int j, char **token);
*/

void	ft_place_token(int fd, char **map, int i, int j, char **token);
void 	print_map(int fd, char **map);
void	ft_print_error(char *str, char *line, int fd);

/*
**	token_functions.c
*/

int		ft_get_the_token(int fd, char ***token);
void	ft_shift_token(char **token, t_point *pad);
int		ft_check_token(char ***token, int cols);
int		ft_get_indexs(int fd, char *str, int *rows, int *cols);
#endif
