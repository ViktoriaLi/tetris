/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:04:41 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/20 19:25:51 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_coordinate
{
	int x;
	int y;
}				t_coordinate;

void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_sqrt(int nb);
void 	if_correct_symb(char *buf, int ret);
void 	if_valid_figures(char *buf);
void  find_links(char **buf, int *i, int *if_star, int *j);
char	***multi_arr_mem(int n, int r, int w);
int   to_multi_arr(char *buf, char ****multi_arr, int strings, int symbols);
char **two_dim_arr_mem(char **field, int numb, char c);
t_coordinate **save_coordinates(char ***all_blocks, int quantity);
void	change_coordinates(t_coordinate *all_coord);
void	normalize_figures(char ***all_blocks, t_coordinate *all_coord);

#endif
