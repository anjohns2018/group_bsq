/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:38:31 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/01 16:25:01 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_matrix
{
	int		o;
	unsigned int	wide;
	unsigned int	deep;
	char		open;
	char		obst;
	char		fill;
}			t_matrix;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			*ft_malloc(int size);
void			run_bsq(char *param, char **argv);
t_matrix		init_map(char *input);
int			get_depth(char *num);
unsigned int		**init_matrix(unsigned int **binary, t_matrix map);
unsigned int		**parse_map(t_matrix map, char *input);
int			min(int a, int b, int c);
void			fill_borders(unsigned int **mtrx, t_matrix map);
void			enumerate_matrix(unsigned int **mtrx, unsigned int **sub, t_matrix map);
void			discover_big_box(unsigned int **mtrx, unsigned int **sub, t_matrix map);
void			overlay_biggest(unsigned int **mtrx, unsigned int max_i, unsigned int max_j, unsigned int max_of_s);
void			print_solution(unsigned int **mtr, t_matrix map);

#endif
