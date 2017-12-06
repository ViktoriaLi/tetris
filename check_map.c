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

void check_symb(char **buf, int *i, int *if_star, int *j)
{
	char *buf1;
	int i1;
	int if_star1;
	int j1;

	buf1 = *buf;;
	i1 = *i;
	if_star1 = *if_star;
	j1 = *j;
	if (buf1[i1 + 1] == '#')
	{
		buf1[i1 + 1] = '*';
		if_star1++;
	}
	if (i1 > 0 && buf1[i1 - 1] == '#')
	{
		buf1[i1 - 1] = '*';
		if_star1++;
	}
	if (j1 >= 5 && buf1[i1 - 5] == '#')
	{
		buf1[i1 - 5] = '*';
		if_star1++;
	}
	if (j1 <= 16 && buf1[i1 + 5] == '#')
	{
		buf1[i1 + 5] = '*';
		if_star1++;
	}
	i1++;
	j1++;
	*buf = buf1;;
	*i = i1;
	*j = j1;
	*if_star = if_star1;
}

void if_valid_figures(char *buf)
{
	int i;
	int j;
	int k;
	int tmp;
	int if_star;

	i = 0;
	while (buf[i] != 0)
	{
		j = 0;
		while (buf[i] != '#')
		{
			i++;
			j++;
		}
		buf[i] = '*';	
		if_star = 1;
		while (if_star > 0)
		{
			if_star = 0;
			if (buf[i] == '*')
				check_symb(&buf, &i, &if_star, &j);
		}
		while (j < 20)
		{
			if (buf[i] == '#')
			{
				ft_putstr("error5\n");
				exit (0);
			}
			if (buf[i] == '*')
				check_symb(&buf, &i, &if_star, &j);
			j++;
			i++;
		}
	i++;
	}
}

void if_correct_symb(char *buf, int ret)
{
	int i;
	int j;
	int k;
	int if_empty;

	i = 0;
	if_empty = 0;
	while (buf[i] != 0 && i < 521)
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
		if (j == 4 && buf[i] != '\n'&& buf[i] != 0)
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
