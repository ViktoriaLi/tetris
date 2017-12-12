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

void paste_figure(char **all_blocks, char ***field, int l, int m, int z)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (all_blocks[i][j] != '*' && j < 4)
			j++;
		while (j < 4)
		{
			if (all_blocks[i][j] == '*')
			 	(*field)[l][m] = all_blocks[i][j] + z;
			if (j < 3 && all_blocks[i][j + 1] == '*')
			 	(*field)[l][m + 1] = 'A' + z;
			if (j > 0 && all_blocks[i][j - 1] == '*')
				(*field)[l][m - 1] = 'A' + z;
			if (i < 3 && all_blocks[i + 1][j] == '*')
				 (*field)[l + 1][m] = 'A' + z;
			if (i > 0 && all_blocks[i - 1][j] == '*')
				 (*field)[l - 1][m] = 'A' + z;
			j++;
			m++;
		}
		i++;
		l++;
	}
}

int check_place(char **all_blocks, char **field, int l, int m)
{
	int i;
	int j;
	int place;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (all_blocks[i][j] == '*')
			{
				place++;
				if (j < 3 && all_blocks[i][j + 1] == '*' && field[l][m + 1] != '.')
					place++;
					//return (0);
				if (j > 0 && all_blocks[i][j - 1] == '*' && field[l][m - 1] != '.')
					place++;
					//return (0);
				if (i < 3 && all_blocks[i + 1][j] == '*' && field[l + 1][m] != '.')
					place++;
						//return (0);
				if (i > 0 && all_blocks[i - 1][j] == '*' && field[l - 1][m] != '.')
					place++;
			}
			j++;
			m++;
		}
		i++;
		l++;
	}
	printf("place %d\n", place);
	return (place);
}

/*void paste_figure(char **all_blocks, char ***field, int l, int m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (all_blocks[i][j] == '*' && j < 4)
				j++;
			if (j < 3 && all_blocks[i][j + 1] == '*')
			 	(*field)[l][m + 1] = all_blocks[i][j + 1];
			if (j > 0 && all_blocks[i][j - 1] == '*')
				(*field)[l][m - 1] = all_blocks[i][j - 1];
			if (i < 3 && all_blocks[i + 1][j] == '*')
				 (*field)[l + 1][m] = all_blocks[i + 1][j];
			if (i > 0 && all_blocks[i - 1][j] == '*')
				 (*field)[l - 1][m] = all_blocks[i - 1][j];
			j++;
			m++;
		}
		i++;
		l++;
	}
}

int check_place(char **all_blocks, char **field, int l, int m)
{
	int i;
	int j;
	//int place;

	i = 0;
	j = 0;
	//place = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (all_blocks[i][j] == '*')
			{
				//place++;
				if (j < 3 && all_blocks[i][j + 1] == '*' && field[l][m + 1] != '.')
					//place++;
					return (0);
				if (j > 0 && all_blocks[i][j - 1] == '*' && field[l][m - 1] != '.')
					//place++;
					return (0);
				if (i < 3 && all_blocks[i + 1][j] == '*' && field[l + 1][m] != '.')
					//place++;
					return (0);
				if (i > 0 && all_blocks[i - 1][j] == '*' && field[l - 1][m] != '.')
					//place++;
					return (0);
			}
			j++;
			//m++;
		}
		i++;
	}
	//printf("place %d\n", place);
	return (1);
}*/

void fill_field(char ***all_blocks, char **field, int quantity, int numb)
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int z;
	int if_place;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	z = 0;
	printf("blocks %d\n", quantity);
	printf("field size %d\n", numb);
	while (l < numb && z < quantity)
	{
		m = 0;
		while (m < numb)
		{
			if (field[l][m] == '.')
			{
				if_place = check_place(all_blocks[z], field, l, m);
				if (if_place > 0)
				{
					paste_figure(all_blocks[z], &field, l, m, z);
					printf("%s\n", "paste figure");
					printf("%s\n", field[0]);
					printf("%s\n", field[1]);
					printf("%s\n", field[2]);
				}
				z++;
			}
			m++;
		}
		l++;
	}
}

void create_field(char ***all_blocks, int quantity)
{
	int i;
	int j;
	int numb;
	char **field;

	i = 0;
	numb = ft_sqrt(quantity * 4);
	field = two_dim_arr_mem(field, numb, '.');
	printf("%s\n", field[0]);
	printf("%s\n", field[1]);
	printf("%s\n", field[2]);

	fill_field(all_blocks, field, quantity, numb);
}

/*void create_field(char ***all_blocks, int quantity)
{
	int i;
	int j;
	int numb;
	char **field;

	i = 0;
	numb = ft_sqrt(quantity * 4);
	field = (char **)malloc(sizeof(char *) * numb);
	while (i < numb)
	{
		field[i] = (char *)malloc(numb);
		i++;
	}
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
	printf("%s\n", "created field");
	while (i--)
		printf("%s\n", field[i]);
	fill_field(all_blocks, field, quantity, numb);
}*/

/*void figures_normalize(char ****all_blocks, int quantity)
{
	int i;
	int j;
	int k;
	int jtmp;
	int ktmp;

	i = 0;
	j = 0;
	k = 0;
	while (i < quantity)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (*all_blocks[i][j][k] != '*' && k < 4)
				k++;
			if (*all_blocks[i][j][k] == '*')
			{
				if (k > 0)
					ktmp = k;
				if (j > 0)
					jtmp = j;
			}
			j++;
		}
		i++;
	}
}*/

void read_file(char *argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE];
	char ***all_blocks;
	int quantity;

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
			all_blocks = multi_arr_mem(26, 4, 5);
			quantity = to_multi_arr(buf, &all_blocks, 4, 4);
			printf("all%s\n", all_blocks[0][0]);
			printf("all%s\n", all_blocks[0][1]);
			printf("all%s\n", all_blocks[0][2]);
			printf("all%s\n", all_blocks[0][3]);
			//free_multi_mem(all_blocks, 26, 4);
			//printf("free%s\n", **all_blocks);

			create_field(all_blocks, quantity);
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
}
