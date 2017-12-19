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

int		check_one(char *s, int *i)
{
	int		count;
	int		y;
	int		r;

	count = 0;
	y = 0;
	r = 0;
	while (s[*i] && y < 4)
	{
		if (s[*i] == '\n' && count == 4)
		{
			y++;
			count = 0;
			*i += 1;
		}
		else if (s[*i] && ((s[*i] != '#' && s[*i] != '.')
		|| (s[*i] != '\n' && count == 4)))
			return (0);
		(s[*i] == '#') ? r++ : r;
		(s[*i] != '\0' && y != 4) ? *i += 1 : *i;
		count++;
	}
	if ((s[*i] && s[*i] != '\n') || (y != 4) || (r != 4))
		return (0);
	return (1);
}

int		ft_check(char *s)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (s[i])
	{
		if (check_one(s, &i) == 0)
			return (0);
		if (s[i] == '\0')
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 0)
		return (0);
	return (check_figures(s));
}

char	*read_file(int fd)
{
	char	*buf;
	int		tetrims;

	tetrims = 0;
	buf = ft_strnew(545);
	while (read(fd, buf, 544))
		tetrims++;
	if (tetrims != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_check(buf) == 1)
	{
		if (check_figures(buf) == 1)
			return (buf);
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
	return (buf);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*vika;
	char	*buf;
	int		blocks;
	char **map;
	int		num;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	buf = read_file(fd);
	vika = coordinate(buf, &blocks);
	num = count_blocks(blocks);
	map = create_field(num);
	while(!fill_field(&map, vika, blocks))
	{
			free_mem(map, num);
			num++;
			map = create_field(num);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
