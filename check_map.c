/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:31:56 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/27 13:32:05 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit_header.h"

void if_valid_figures(char *buf)
{
	
}

void if_correct_symb(char *buf)
{
	int i;
	int j;
	int k;
	int if_empty;

	i = 0;
	if_empty = 0;
	while (buf[i] != 0)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4 && (buf[i] == '.' || buf[i] == '#'))
			{
				if (buf[i] == '#')
					if_empty++;
				i++;
				k++;
			}
			if ((k == 4 && buf[i] != '\n') || (k < 4 && buf[i] != '.' && buf[i] != '#'))
			{
				ft_putstr("error2\n");
				exit (0);
			}
			i++;
			j++;
		}
		if (j == 4 && buf[i] != '\n' && buf[i + 1] != '\n' && buf[i + 1] != 0)
		{
			ft_putstr("error3\n");
			exit (0);
		}
		i++;
	}
	if (if_empty == 0 || if_empty % 4 != 0)
	{
		ft_putstr("error4\n");
		exit (0);
	}
}
