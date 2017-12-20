/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:59:31 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/20 16:11:26 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 545

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_coordinate
{
	int x;
	int y;
}				t_coordinate;

void			ft_putstr(char const *s);
char			*read_file(char *s);
char			*ft_strnew(size_t size);
int				ft_check(char *s);
int				check_one(char *s, int *i);
int				check_figures(char *s);
t_list			*coordinate(char *s, int *blocks);
void			save_coordinateone(char *s, t_list **list, int *i, int blocks);
void			coordinatemin(t_coordinate c[4]);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			list_push_back(t_list **begin_list, t_list *new);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_sqrt(int nb);
char			**create_field(int blocks);
int				fill_field(char ***field, t_list *list, int blocks, int num);
int				check_in_field(char **field, t_list *list, int i, int j);
void			add_elem_in_field(char ***field, t_list *list, int i, int j);
void			remove_figure(char ***field, t_list *list, int i, int j);
void			if_solution(char ***field, t_list **list, int num);
char			**free_mem(char **field, int num);
void			ft_lstdel(t_list **alst);

#endif
