/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:31:15 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/01 14:51:44 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define BUF_SIZE 4096

int				main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		run_bsq(argv[0], argv);
		ft_putchar('\n');
		return (0);
	}
	else
		while (i < argc)
		{
			run_bsq(argv[i++], argv);
			ft_putchar('\n');
		}
	return (0);
}

void			run_bsq(char *param, char **argv)
{
	int			file;
	int			spot;
	char		map[BUF_SIZE + 1];
	t_matrix	mat;

	if (param == argv[0])
		spot = read(0, map, BUF_SIZE + 1);
	else
	{
		file = open(param, O_RDONLY);
		if (file != -1)
			spot = read(file, map, BUF_SIZE + 1);
		else
		{
			ft_putstr("map error\n");
			return ;
		}
	}
	map[spot] = '\0';
	mat = init_map(map);
	fill_borders(parse_map(mat, map), mat);
	if (!(param == argv[0]))
		if (close(file) == -1)
			ft_putstr("close error\n");
}

t_matrix		init_map(char input[BUF_SIZE + 1])
{
	t_matrix	matrix;
	int			i;
	int			o;

	i = 1;
	while (input[i] <= '9' && input[i] >= '0')
		i++;
	o = i;
	i += 5 + o;
	while (input[i] != '\n')
		i++;
	matrix.wide = i - (5 + o);
	matrix.deep = (get_depth(input));
	matrix.open = input[0 + o];
	matrix.obst = input[1 + o];
	matrix.fill = input[2 + o];
	matrix.o = o;
	return (matrix);
}

unsigned int	**init_matrix(unsigned int **binary, t_matrix map)
{
	unsigned int i;

	i = 0;
	binary = ft_malloc(sizeof(unsigned int) * (map.deep) * (map.wide));
	while (i < map.deep)
	{
		binary[i++] = (unsigned int *)ft_malloc(sizeof(unsigned int) * (map.wide));
	}
	return (binary);
}

unsigned int	**parse_map(t_matrix map, char input[BUF_SIZE + 1])
{
	unsigned int				**binary;
	int					row;
	int					col;
	int					i;

	row = 0;
	col = 0;
	binary = NULL;
	binary = init_matrix(binary, map);
	i = 5 + map.o;
	while (input[i])
	{
		if (input[i] == map.open)
			binary[row][col++] = 1;
		else if (input[i] == map.obst)
			binary[row][col++] = 0;
		else if (input[i] == '\n')
		{
			col = 0;
			row++;
		}
		i++;
	}
	return (binary);
}
