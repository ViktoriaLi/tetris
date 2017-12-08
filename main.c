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

#define BUF_SIZE 547

void check_place(char **all_blocks, char **field, int m, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fiels[l][m]
	while (all_blocks)
	{
		j = 0;
		while (all_blocks[i][j] != '#' && j < 4)
			j++;
		if (all_blocks[i][j] == '#')
		{
			if (all_blocks[i][j + 1] == '#')
			{
				
			}
		}
		i++;
	}


}

void fill_field(char ***all_blocks, char ***field, int quantity, int numb)
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int z;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	z = 0;
	printf("blocks %d\n", quantity);
	printf("field size %d\n", numb);
	while (field)
	{
		m = 0;
		while (field[l][m] != '.' && m < numb)
		{
			m++;
		}
		check_place(all_blocks[z], &field, m, l);
		l++;
	}


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
						if (all_blocks[i][j][k] == '*')
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
	printf("%s\n", field[0]);
	printf("%s\n", field[1]);
	printf("%s\n", field[2]);
	printf("%s\n", field[3]);
}

/*
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
					if (all_blocks[i][j][k] == '*')
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
*/

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
		field[i] = (char *)malloc(numb + 1);
		i++;
	}
	field[i] = NULL;
	i = 0;
	while (i < numb)
	{
		j = 0;
		while (j < numb)
		{
			field[i][j] = '.';
			j++;
		}
		i++;
	}
	printf("%s\n", field[0]);
	printf("%s\n", field[1]);
	printf("%s\n", field[2]);
	printf("%s\n", field[3]);
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
	while (buf[l] != 0)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				all_blocks[i][j][k] = buf[l];
				k++;
				l++;
			}
			l++;
			j++;
		}
		l++;
		i++;
	}
	printf("1%s\n", all_blocks[0][0]);
	printf("2%s\n", all_blocks[0][1]);
	printf("3%s\n", all_blocks[0][2]);
	printf("4%s\n", all_blocks[0][3]);
	printf("1%s\n", all_blocks[1][0]);
	printf("2%s\n", all_blocks[1][1]);
	printf("3%s\n", all_blocks[1][2]);
	printf("4%s\n", all_blocks[1][3]);
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
	ret = read(fd, &buf, BUF_SIZE);
	if (ret > 0)
		{
			if (buf[BUF_SIZE - 1] != 0)
			{
				ft_putstr("errormax\n");
				exit (0);
			}
			printf ("read bufer\n%s\n", buf);
			printf ("symbols quantity\n%d\n", ret);
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
		ft_putstr("usage: ./a.out filename");
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
