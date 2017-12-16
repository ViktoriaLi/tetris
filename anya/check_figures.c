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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//#include "libft.h"
#include "fillit.h"

int	check_figures(char *s)
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
		{
			printf("%d\n %d\n", i, ir);
			return (0);
		}
		(s[i]) ? i++ : i;
	}
	return (1);
}
