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

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 545

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

char	*read_file(char *s);
int		check_one(char *s, int *i);
int		ft_check(char *s);
int	check_figures(char *s);
t_list	*coordinate(char *s, int *blocks);
char	**create_field(int blocks);
int	check_in_field(char **field, t_list *list, int i, int j);
void add_elem_in_field(char ***field, t_list *list, int i, int j);
t_list	*ft_lstnew(void const *content, size_t content_size);
int	ft_sqrt(int nb);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strnew(size_t size);
void	ft_putstr(char const *s);
int		fill_field(char ***field, t_list *list, int blocks, int num);
void remove_figure(char ***field, t_list *list, int i, int j);
char **free_mem(char **field, int num);
void if_correct_symb(char *buf);
void if_valid_figures(char *buf);
void find_links(char **buf, int *i, int *if_star, int *j);
void check_symb(char **buf, int *i, int *if_star, int *j);
void	ft_lstdel(t_list **alst);
void if_solution(char ***field, t_list **list, int num);

#endif
