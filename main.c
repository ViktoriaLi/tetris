/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:20:32 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/22 15:58:30 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit_header.h"

#define BUF_SIZE 4096

void fill_field(char ***all_blocks, char **field, int quantity, int numb)
{
	int i;
	int j;
	int k;
	int l;
	int m;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	printf("%d\n", quantity);
	printf("%d\n", numb);

	while (l < numb)
	{
		m = 0;
		while (m < numb)
		{
			while (i < numb)
			{
				j = 0;
				while (j < 4)
				{
					k = 0;
					while (k < 4)
					{
						if (all_blocks[i][j][k] == '#')
						{
							field[l][m] = all_blocks[i][j][k];
							m++;
						}
						k++;
					}
					j++;
				}
				i++;
			}
			m++;
		}
		l++;
	}
}
	

	/*while (i < quantity && l < numb)
	{
		while (k < 4 && all_blocks[i][j][k] == '#')
		{
			field[l][m] = all_blocks[i][j][k];
			m++;
			k++;
		}
		k++;
	}
	printf("%s\n", *field);
}*/





	/*while (l < numb)
	{
		m = 0;
		while (m < numb)
		{
			while (i < numb)
			{
				l = 0;
				j = 0;
				while (j < 4)
				{
					k = 0;
					while (k < 4 && j < 4)
					{
						if (all_blocks[i][j][k] == '#')
						{
							while (all_blocks[i][j][k] == '#')
							{
								field[l][m] = all_blocks[i][j][k];
								m++;
								k++;
							}
							k = 0;
							l++;
							j++;
						}
						else
							k++;					
					}
					j++;
				}
				i++;
			}
			m++;
		}
		l++;
	}*/
	


void create_field(char ***all_blocks, int quantity)
{
	int i;
	int j;
	int numb;
	char **field;

	i = 0;
	numb = ft_sqrt(quantity * 4);
	field = (char **)malloc(sizeof(char *) * numb + 1);
	while (i < numb)
	{
		field[i] = (char *)malloc(numb);
		i++;
	}
	//field[i] = NULL;
	i = 0;
	j = 0;
	while (i < numb)
	{
		while (j < numb)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = '\n';
		i++;
	}
	fill_field(all_blocks, field, quantity, numb);
}

void save_blocks(char *buf, char ***all_blocks)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	l = 0;
	while ((buf[l] == '.' || buf[l] == '#' || buf[l] == '\n') && buf[l] != 0)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4 && (buf[l] == '.' || buf[l] == '#'))
			{
				all_blocks[i][j][k] = buf[l];
				k++;
				l++;
			}
			if ((k == 4 && buf[l] != '\n') || (k < 4 && buf[l] != '.' && buf[l] != '#'))
			{
				ft_putstr("error0\n");
				exit (0);
			}
			l++;
			j++;
		}
		l++;
		i++;
	}
	printf("%s\n", all_blocks[0][0]);
	printf("%s\n", all_blocks[0][1]);
	printf("%s\n", all_blocks[0][2]);
	printf("%s\n", all_blocks[0][3]);
	printf("%s\n", all_blocks[1][0]);
	printf("%s\n", all_blocks[1][1]);
	printf("%s\n", all_blocks[1][2]);
	printf("%s\n", all_blocks[1][3]);
	if (buf[l] != 0)
	{
		ft_putstr("error1\n");
		exit (0);
	}
	else
		create_field(all_blocks, i);
}

char ***blocks_memory()
{
	int i;
	int j;
	char ***all_blocks;
	char *data;
	char **ptr;

	i = 0;
	j = 0;
	all_blocks = (char ***)malloc(sizeof(char **) * 26 + 
		sizeof(char *) * 26 * 4 + 
		sizeof(char) * 26 * 4 * 5);
	ptr = (char **)(all_blocks + 26);
	data = (char *)(all_blocks + 26 + 26 * 4);
	while (i < 26)
	{
		all_blocks[i] = ptr + i * 4;
		j = 0;
		while (j < 4)
		{
			all_blocks[i][j] = data + i * 4 * 5 + j * 5;
			all_blocks[i][j][4] = 0;
			j++;
		}
		i++;
	}
	return (all_blocks);
}

void read_file(char *argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE];

	fd = open(argv, O_RDONLY);
	ret = read(fd, &buf, 4096);
	if (ret > 0)
		{
			printf ("%s\n", buf);
			printf ("%d\n", ret);
			if_correct_symb(buf, ret);
			if_valid_figures(buf);
			save_blocks(buf, blocks_memory());
		}
	close(fd);	
}

int if_valid_argv(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage: You should send one file as parameter");
		exit(1);
	}
	return (3);
}

int	main(int argc, char **argv)
{
	if (if_valid_argv(argc))
		read_file(argv[1]);
	
	//exit (0);
}
/*int	main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char dest[4][4];

	i = 0;
	k = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: You should send one file as parameter");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, &buf, 4097);
	if (ret)
		while (i < 4)
		{
			j = 0;
			while (k < ret)
			{
				dest[i][j] = buf[k];
				j++;
				k++;
			}
			i++;
		}
	
	close(fd);
	exit (0);
}*/
