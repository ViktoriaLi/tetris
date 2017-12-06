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

/*void check_symb(buf, i, if_star)
{
	printf ("10%s\n", buf);
	if (buf[i + 1] == '#')
	{
		buf[i + 1] = '*';
		if_star++;
	}
	printf ("11%s\n", buf);
	if (i > 0 && buf[i - 1] == '#')
	{
		buf[i - 1] = '*';
		if_star++;
	}
	printf ("12%s\n", buf);
	if (j >= 5 && buf[i - 5] == '#')
	{
		buf[i - 5] = '*';
		if_star++;
	}
	printf ("13%s\n", buf);
	if (j <= 16 && buf[i + 5] == '#')
	{
		buf[i + 5] = '*';
		if_star++;
	}
	printf ("14%s\n", buf);
}*/

void if_valid_figures(char *buf)
{
	int i;
	int j;
	int k;
	int tmp;
	int if_star;

	i = 0;
	j = 0;
	k = 0;
	printf("9%s\n", buf);
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
			{
				//check_symb(&buf, i, if_star);
				printf ("10%s\n", buf);
				if (buf[i + 1] == '#')
				{
					buf[i + 1] = '*';
					if_star++;
				}
				printf ("11%s\n", buf);
				if (i > 0 && buf[i - 1] == '#')
				{
					buf[i - 1] = '*';
					if_star++;
				}
				printf ("12%s\n", buf);
				if (j >= 5 && buf[i - 5] == '#')
				{
					buf[i - 5] = '*';
					if_star++;
				}
				printf ("13%s\n", buf);
				if (j <= 16 && buf[i + 5] == '#')
				{
					buf[i + 5] = '*';
					if_star++;
				}
				printf ("14%s\n", buf);
				i++;
				j++;
			}
		}
		printf ("15%s\n", buf);
		while (j < 20)
		{
			if (buf[i] == '#')
			{
				ft_putstr("error5\n");
				exit (0);
			}
			if (buf[i] == '*')
			{
				printf ("10%s\n", buf);
				if (buf[i + 1] == '#')
				{
					buf[i + 1] = '*';
					if_star++;
				}
				printf ("11%s\n", buf);
				if (i > 0 && buf[i - 1] == '#')
				{
					buf[i - 1] = '*';
					if_star++;
				}
				printf ("12%s\n", buf);
				if (j >= 5 && buf[i - 5] == '#')
				{
					buf[i - 5] = '*';
					if_star++;
				}
				printf ("13%s\n", buf);
				if (j <= 16 && buf[i + 5] == '#')
				{
					buf[i + 5] = '*';
					if_star++;
				}
				printf ("14%s\n", buf);
				i++;
				j++;
			}
			j++;
			i++;
		}
	i++;
	}
}


/*
	while (buf[i] != 0)
	{
		j = 0;
		while (buf[i] != '#')
		{
			i++;
			j++;
		}
		buf[i] = '*';
		while (j < 21)
		{		
			while (if_star > 0)
			{
				if_star = 0;
				if (buf[i] == '*')
				{
					if (buf[i + 1] == '#')
					{
						buf[i + 1] = '*';
						if_star++;
					}
					if (i > 0 && buf[i - 1] == '#')
					{
						buf[i - 1] = '*';
						if_star++;
					}
					if (j > 5 && buf[i - 5] == '#')
					{
						buf[i - 5] = '*';
						if_star++;
					}
					if (j < 16 && buf[i + 5] == '#')
					{
						buf[i + 5] = '*';
						if_star++;
					}
				}
			}
			i++;
			j++;
		}
		tmp = i;
		printf ("10%s\n", buf);
		while (j > 0)
		{
			if (buf[tmp] == '#')
			{
				ft_putstr("error5\n");
				exit (0);
			}
			j--;
			tmp--;
		}
		i++;
	}
}
*/
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
