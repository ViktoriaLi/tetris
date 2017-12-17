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
			{
				 	(*field)[l][m] = 'A' + z;
					if (j < 3 && all_blocks[i][j + 1] == '*')
			 		(*field)[l][m + 1] = 'A' + z;
					if (j > 0 && all_blocks[i][j - 1] == '*')
					(*field)[l][m - 1] = 'A' + z;
					if (i < 3 && all_blocks[i + 1][j] == '*')
				 	(*field)[l + 1][m] = 'A' + z;
					if (i > 0 && all_blocks[i - 1][j] == '*')
				 	(*field)[l - 1][m] = 'A' + z;
				}
			j++;
			//m++;
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
				//place++;
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
				//m++;
			}
			j++;
			//m++;
		}
		i++;
		l++;
	}
	printf("place %d\n", place);
	return (place);
}

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
	while (l < numb)
	{
		m = 0;
		while (m < numb)
		{
			if (field[l][m] == '.')
			{
					while(z < quantity)
					{
							if (check_place(all_blocks[z], field, l, m) > 2)
							{
								paste_figure(all_blocks[z], &field, l, m, z);
								printf("%s\n", "paste figure");
								printf("%s\n", field[0]);
								printf("%s\n", field[1]);
								printf("%s\n", field[2]);
							}
							z++;
					}
				}
			m++;
		}
		l++;
	}
}

void create_field(char ***all_blocks, int quantity)
{
	int numb;
	char **field;

	numb = ft_sqrt(quantity * 4);
	field = two_dim_arr_mem(field, numb, '.');
	printf("%s\n", field[0]);
	printf("%s\n", field[1]);
	printf("%s\n", field[2]);

	fill_field(all_blocks, field, quantity, numb);
}

/*
void	figures_normalize(t_coordinate ***all_coord, int quantity)
{
	int minx;
	int miny;
	int i;
	int grid;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < quantity)
	{
		grid = 0;
		while (grid < 4)
		{
			if ((*all_coord)[i][grid].x < minx)
				minx = (*all_coord)[i][grid].x;
			if ((*all_coord)[i][grid].y < miny)
				miny = (*all_coord)[i][grid].y;
			grid++;
		}
		grid = 0;
		while (grid < 4)
		{
			(*all_coord)[i][grid].x = (*all_coord)[i][grid].x - minx;
			(*all_coord)[i][grid].y = (*all_coord)[i][grid].y - miny;
			grid++;
		}
		i++;
	}
}*/

void	normalize_figures(char ***all_blocks, t_coordinate *all_coord)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == all_coord[j].y && j == all_coord[j].x)
					(*all_blocks)[i][j] = '#';
			else
				(*all_blocks)[i][j] = '.';
			k++;
			j++;
		}
		i++;
	}
}
void	change_coordinates(t_coordinate *all_coord)
{
	int minx;
	int miny;
	int i;
	int grid;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 4)
	{
		if (all_coord[i].x < minx)
			minx = all_coord[i].x;
		if (all_coord[i].y < miny)
			miny = all_coord[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		all_coord[i].x = all_coord[i].x - minx;
		all_coord[i].y = all_coord[i].y - miny;
		i++;
	}
}

t_coordinate **save_coordinates(char ***all_blocks, int quantity)
{
	int i;
	int j;
	int k;
	int grid;
	int t;
	t = 0;
	t_coordinate **all_coord;
	all_coord = (t_coordinate **)malloc(sizeof(t_coordinate *) * quantity);
	while (t < quantity)
	{
		all_coord[t] = (t_coordinate *)malloc(sizeof(t_coordinate) * 4);
		t++;
	}
	i = 0;
	while (i < quantity)
	{
		j = 0;
		grid = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (all_blocks[i][j][k] == '*')
					{
						all_coord[i][grid].x = k;
						all_coord[i][grid].y = j;
						grid++;
					}
				k++;
			}
			j++;
		}
		change_coordinates(all_coord[i]);
		normalize_figures(&all_blocks[i], all_coord[i]);
		i++;
	}

	i = 0;
	grid = 0;
	while (i < quantity)
	{
		grid = 0;
		while (grid < 4)
		{
			printf("%d %d\n", all_coord[i][grid].y, all_coord[i][grid].x);
			grid++;
		}
		i++;
	}
	return (all_coord);
}

void read_file(char *argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE];
	char ***all_blocks;
	int quantity;
	t_coordinate **all_coord;

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
			all_coord = save_coordinates(all_blocks, quantity);
			//figures_normalize(all_coord, quantity);
			printf("all%s\n", all_blocks[0][0]);
			printf("all%s\n", all_blocks[0][1]);
			printf("all%s\n", all_blocks[0][2]);
			printf("all%s\n", all_blocks[0][3]);
			printf("all%s\n", all_blocks[1][0]);
			printf("all%s\n", all_blocks[1][1]);
			printf("all%s\n", all_blocks[1][2]);
			printf("all%s\n", all_blocks[1][3]);
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
