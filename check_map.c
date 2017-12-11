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
	if ((*buf)[*i + 1] == '#')
	{
		(*buf)[*i + 1] = '*';
		(*if_star)++;
	}
	if (*i > 0 && (*buf)[*i - 1] == '#')
	{
		(*buf)[*i - 1] = '*';
		(*if_star)++;
	}
	if (*j >= 5 && (*buf)[*i - 5] == '#')
	{
		(*buf)[*i - 5] = '*';
		(*if_star)++;
	}
	if (*j <= 16 && (*buf)[*i + 5] == '#')
	{
		(*buf)[*i + 5] = '*';
		(*if_star)++;
	}
	(*i)++;
	(*j)++;
}

void find_links(char **buf, int *i, int *if_star, int *j)
{
	while ((*j) < 20)
	{
		while ((*buf)[*i] != '#')
		{
			(*i)++;
			(*j)++;
		}
		(*buf)[*i] = '*';
		*if_star = 1;
		while (*if_star > 0)
		{
			(*if_star)--;
			if ((*buf)[*i] == '*')
				check_symb(buf, i, if_star, j);
		}
		while ((*j) < 21)
		{
			if ((*buf)[*i] == '*')
				check_symb(buf, i, if_star, j);
				(*j)++;
				(*i)++;
		}
	}
}

void if_valid_figures(char *buf)
{
	int i;
	int j;
	int if_star;

	i = 0;
	while (buf[i] != 0)
	{
		j = 0;
		find_links(&buf, &i, &if_star, &j);
		i = i - j;
		j = 0;
		while (j < 20)
		{
			if (buf[i] == '*')
				check_symb(&buf, &i, &if_star, &j);
			j++;
			i++;
		}
		i = i - j;
		j = 0;
		while (j < 20)
		{
			if (buf[i] == '#')
			{
				printf ("8\n%s\n", buf);
				ft_putstr("error5\n");
				exit (0);
			}
			j++;
			i++;
		}
		i++;
	}
	printf ("check figures bufer\n%s\n", buf);
}

void if_correct_symb(char *buf, int ret)
{
	int i;
	int j;
	int k;
	int if_empty;

	i = 0;
	if_empty = 0;
	while (buf[i] != 0 && i < 546)
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
if (if_empty == 0 || if_empty % 4 != 0)
	{
		printf("%d\n", if_empty);
		printf("%d\n", ret);
		ft_putstr("error4\n");
		exit (0);
	}

}
