/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:41:56 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 14:35:18 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_memdel2d(char ***ap)
{
	char	**map;
	int		i;

	i = 0;
	map = *ap;
	if (map)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		*ap = NULL;
	}
}
