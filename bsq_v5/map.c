/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 05:46:13 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/01 16:38:21 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "stdio.h"

void	fill_borders(unsigned int **mtrx, t_matrix map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	**sub;

	i = 0;
	sub = ft_malloc(sizeof(unsigned int) * map.deep * map.wide);
	while (i < map.deep)
		sub[i++] = (unsigned int *)ft_malloc(sizeof(unsigned int) * map.wide);
	i = 0;
	while (i < map.deep)
	{
		sub[i][0] = mtrx[i][0];
		i++;
	}
	j = 0;
	while (j < map.wide)
	{
		sub[0][j] = mtrx[0][j];
		j++;
	}
	enumerate_matrix(mtrx, sub, map);
}

void	enumerate_matrix(unsigned int **mtrx, unsigned int **sub, t_matrix map)
{
	unsigned int i;
	unsigned int j;

	i = 1;
	while (i < map.deep)
	{
		j = 1;
		while (j < map.wide)
		{
			if (mtrx[i][j] == 1)
				sub[i][j] = min(sub[i][j - 1], sub[i - 1][j], sub[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
	discover_big_box(mtrx, sub, map);
}

void	discover_big_box(unsigned int **mtrx, unsigned int **sub, t_matrix map)
{
	unsigned int	max_of_s;
	unsigned int	max_i;
	unsigned int	max_j;
	unsigned int	i;
	unsigned int	j;

	max_of_s = sub[0][0];
	max_i = 0;
	max_j = 0;
	i = -1;
	while (++i < map.deep)
	{
		j = -1;
		while (++j < map.wide)
		{
			if (max_of_s < sub[i][j])
			{
				max_of_s = sub[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	printf("max_i is %d, max_j = %d, max_of_s = %d\n", max_i, max_j, max_of_s);
	overlay_biggest(mtrx, max_i, max_j, max_of_s - 1);
	print_solution(mtrx, map);
}

void	overlay_biggest(unsigned int **mtrx, unsigned int max_i, unsigned int max_j, unsigned int max_of_s)
{
	unsigned int i;
	unsigned int j;

	i = max_i;
	while (i + 1 > max_i - max_of_s)
	{
		j = max_j;
		while (j + 1 > max_j - max_of_s)
		{
			mtrx[i][j] = 2;
			j--;
		}
		i--;
	}
}

void	print_solution(unsigned int **mtrx, t_matrix map)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < map.deep)
	{
		j = 0;
		while (j <= map.wide)
		{
			if (mtrx[i][j] == 0)
				ft_putchar(map.obst);
			else if (mtrx[i][j] == 1)
				ft_putchar(map.open);
			else if (mtrx[i][j] == 2)
                		ft_putchar(map.fill);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
