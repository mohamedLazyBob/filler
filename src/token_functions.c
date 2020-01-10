/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 05:27:49 by mzaboub           #+#    #+#             */
/*   Updated: 2020/01/10 13:52:19 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** ***************************************************************************
*/

int				ft_get_the_token(int fd, char ***token)
{
	int		lines;
	int		cols;
	int		i;

	if (ft_get_indexs(fd, "Piece", &lines, &cols) == FALSE)
		return (FALSE);
	if (!(*token = (char**)malloc(sizeof(char*) * (lines + 1))))
	{
		perror("piece isn't allocated ");
		return (FALSE);
	}
	i = -1;
	while (++i < lines)
		get_next_line(0, *token + i);
	(*token)[i] = NULL;
	return (ft_check_token(token, cols));
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

/*
** ***************************************************************************
*/

void			ft_shift_token(char **token, t_point *pad)
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

int				ft_check_token(char ***token, int cols)
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
		if (j < cols)
		{
			ft_memdel2d(token);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/*
** ***************************************************************************
*/

int				ft_get_indexs(int fd, char *str, int *rows, int *cols)
{
	char	*line;
	char	**splt;

	get_next_line(0, &line);
	splt = ft_strsplit(line, ' ');
	ft_memdel((void**)&line);
	if (ft_strequ(str, splt[0]) == FALSE)
	{
		ft_memdel2d(&splt);
		return (FALSE);
	}
	splt[2][ft_strlen(splt[2]) - 1] = '\0';
	if ((ft_isstrdigit(splt[1]) == FALSE) || (ft_isstrdigit(splt[2]) == FALSE))
	{
		ft_memdel2d(&splt);
		ft_print_error("Line/numbers, ins't valid.\n", str, fd);
		return (FALSE);
	}
	*rows = ft_atoi(splt[1]);
	*cols = ft_atoi(splt[2]);
	ft_memdel2d(&splt);
	if (*rows <= 0 || *cols <= 0)
		return (FALSE);
	return (TRUE);
}

/*
** ***************************************************************************
*/
