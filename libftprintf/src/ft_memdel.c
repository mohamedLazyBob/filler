/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:41:56 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/09 11:14:32 by mzaboub          ###   ########.fr       */
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
void			ft_memdel2d(char ***map)
{
	char	**ap;
	int		i;

	ap = *map;
	i = 0;
	if (map && ap)
	{
		while (ap[i] != NULL)
		{
			free(ap[i]);
			ap[i] = NULL;
			i++;
		}
		ft_memdel((void**)*map);
		*map = NULL;
	}
}
