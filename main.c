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

#include "fillit_header.h"

#define BUF_SIZE 4096


int	main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char **dest[4][4];

	i = 0;
	k = 0;
	if (argc != 2)
		exit(0);
	//dest = (unsigned char **)malloc(sizeof(unsigned char *) * 2);
	//dest = (unsigned char **)malloc(sizeof(unsigned char *) * 2);
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, &buf, BUF_SIZE)))
	{
		ft_putstr(buf);
		/*while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				dest[i][j] = buf[k];
				j++;
				k++;
			}
			i++;
		}*/
	}
	close(fd);
}
