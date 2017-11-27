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
	int i;
	int j;
	int k;
	int grids;
	int tmp;

	i = 0;
	j = 0;
	k = 0;
	grids = 4;
	tmp = grids;;
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
		{
			while (buf[i] == '#' && buf[i] != '\n')
			{
				i++;
				grids--;
			}
			if (grids == tmp)
			{
				ft_putstr("error5\n");
				exit (0);
			}
			
			if (grids != 0)
				i += 4;
			tmp = grids;
		}
		i++;
	}


	/*while (buf[i] != 0)
	{
		grids = 4;
		j = 0;
		while (grids >= 0 && j < 21)
		{
			if (buf[i] == '#')
			{
				while (buf[i++] == '#')
					grids--;
				while (grids != 0)
				{
					i += 4;
					while (buf[i] == '#')
					{
						i++;
						grids--;
					}
				}
			}
			i++;
			j++;
		}
		i++;
	}*/
	

	/*while (buf[i] != 0)
	{
		j = 0;
		grids = 0;
		while (grids <= 4 && j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (buf[i] == '#')
					grids++;
				i++;
				k++;
			}
			i++;
			j++;
		}
		i++;
	}*/
}

void if_correct_symb(char *buf, int ret)
{
	int i;
	int j;
	int k;
	int if_empty;

	i = 0;
	if_empty = 0;
	while (i < 521 && buf[i] != 0)
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
	if ((i == 521 && buf[i] != 0) || if_empty == 0 || if_empty % 4 != 0 || if_empty / 4 != ret / 20)
	{
		printf("%d\n", if_empty);
		printf("%d\n", ret);
		ft_putstr("error4\n");
		exit (0);
	}

}
