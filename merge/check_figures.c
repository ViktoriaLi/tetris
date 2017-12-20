/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:12:06 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/07 14:12:07 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_one(char *s, int *i)
{
	int		count;
	int		y;
	int		r;

	count = 0;
	y = 0;
	r = 0;
	while (s[*i] && y < 4)
	{
		if (s[*i] == '\n' && count == 4)
		{
			y++;
			count = 0;
			*i += 1;
		}
		else if (s[*i] && ((s[*i] != '#' && s[*i] != '.') ||
			(s[*i] != '\n' && count == 4)))
			return (0);
		(s[*i] == '#') ? r++ : r;
		(s[*i] != '\0' && y != 4) ? *i += 1 : *i;
		count++;
	}
	if ((s[*i] && s[*i] != '\n') || (y != 4) || (r != 4))
		return (0);
	return (1);
}

int		ft_check(char *s)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (s[i])
	{
		if (check_one(s, &i) == 0)
			return (0);
		if (s[i] == '\0')
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 0)
		return (0);
	return (check_figures(s));
}

int		check_figures(char *s)
{
	int i;
	int symbofblock;
	int ir;

	i = 0;
	while (s[i])
	{
		symbofblock = 0;
		ir = 0;
		while (s[i] && symbofblock < 20)
		{
			if (s[i] == '#')
			{
				if (s[i + 1] == '#')
					ir++;
				if (symbofblock > 0 && s[i - 1] == '#')
					ir++;
				if (symbofblock >= 5 && s[i - 5] == '#')
					ir++;
				if (symbofblock <= 15 && s[i + 5] == '#')
					ir++;
			}
			symbofblock++;
			i++;
		}
		if (!(ir == 6 || ir == 8))
			return (0);
		(s[i]) ? i++ : i;
	}
	return (1);
}
