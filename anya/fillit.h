/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:59:31 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/07 14:59:31 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct	s_coordinate
{
	int x;
	int y;
}				t_coordinate;

char	*read_file(int fd);
int		check_figures(char *s);
t_list	*coordinate(char *s, int *blocks);
char	**create_field(int blocks);
void add_elem_in_field(char ***field, t_list *list, int i, int j, int blocks);
int		count_blocks(int blocks);
t_list	*ft_lstnew(void const *content, size_t content_size);
int	ft_sqrt(int nb);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strnew(size_t size);
void	ft_putstr(char const *s);
int		fill_field(char ***field, t_list *list, int blocks);
void remove_figure(char ***field, t_list *list, int i, int j, int blocks);
char **free_mem(char **field, int num);

#endif
