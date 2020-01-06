/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:41:56 by mzaboub           #+#    #+#             */
/*   Updated: 2019/05/08 00:19:39 by mzaboub          ###   ########.fr       */
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
void			ft_memdel2d(void ***map)
{
	char	**ap;
	int 	i;

	ap = (char**)*map;
	i = 0;
	while (ap + i != NULL)
	{
		free (ap + i);
		i++;
	}
	free(ap);
	*map = 0;
}