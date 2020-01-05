/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:05:46 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/04 23:49:22 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "../libftprintf/headers/ft_printf.h"

/*		resolve.c	*/

int		ft_place_token(char **map, int player, int fd);



/*		parser.c	*/
void	ft_parse_input(int fd);
void	ft_get_the_map(int fd, char ***map);
void	ft_get_player(int *player, int fd);
void	print_map(int fd, int x, int y, char **map);
#endif
