/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:41:52 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/03 15:41:53 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**free_mem(char **field, int num)
{
	int i;

	i = 0;
	while (i <= num)
	{
		free(field[i]);
		field[i] = NULL;
		i++;
	}
	free(field);
	field = NULL;
	return (field);
}

char	**create_field(int num)
{
	int		i;
	int		j;
	char	**field;

	i = 0;
	field = (char **)malloc(sizeof(char *) * (num + 1));
	field[num] = NULL;
	while (i < num)
	{
		field[i] = (char*)malloc(sizeof(char) * (num + 1));
		i++;
	}
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = '\0';
		i++;
	}
	return (field);
}

char	*read_file(char *s)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(s, O_RDONLY);
	buf = ft_strnew(BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE + 1);
	close(fd);
	if (ret > 0)
	{
		if (buf[BUF_SIZE] != 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (ft_check(buf) == 1)
		{
			if (check_figures(buf) == 1)
				return (buf);
		}
	}
	ft_putstr("error\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		num;
	int		blocks;
	char	*buf;
	char	**map;
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("usage: ./a.out filename");
		return (0);
	}
	if (!(read_file(argv[1])))
		return (0);
	buf = read_file(argv[1]);
	list = coordinate(buf, &blocks);
	num = ft_sqrt(blocks * 4);
	map = create_field(num);
	while (!fill_field(&map, list, blocks, num))
	{
		free_mem(map, num);
		num++;
		map = create_field(num);
	}
}
