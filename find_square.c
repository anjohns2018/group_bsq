/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:42:48 by ajohnson          #+#    #+#             */
/*   Updated: 2018/04/01 02:06:27 by ajohnson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define bool int
#define R 10
#define C 10

int min(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}

void	print_sub_matrix(bool M[R][C])
{
	int i, j;
	int S[R][C];
	int max_of_s, max_i, max_j;

	i = 0;
	while (i < R)
	{
		S[i][0] = M[i][0];
		i++;
	}

	j = 0;
	while (j < C)
	{
		S[0][j] = M[0][j];
		j++;
	}

	i = 1;
	while (i < R)
	{
		j = 1;
		while (j < C)
		{
			if (M[i][j] == 1)
				S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
			else
				S[i][j] = 0;
			j++;
		}
		i++;
	}

	max_of_s = S[0][0]; max_i = 0; max_j = 0;
	i = 0;
	while (i < R)
	{
		j = 0;
		while (j < C)
		{
			if (max_of_s < S[i][j])
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}

	i = max_i;
	while (i > max_i - max_of_s)
	{
		j = max_j;
		while (j > max_j - max_of_s)
		{
			printf("%d", M[i][j]);
			j--;
		}
		i--;
		printf("\n");
	}
}

int	main()
{
	bool M[R][C] = {{0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
					{1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
					{0, 1, 1, 1, 1, 1, 0, 0, 1, 1},
					{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
					{0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
					{0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
					{1, 1, 1, 0, 0, 1, 1, 0, 1, 1},
					{0, 0, 0, 1, 1, 0, 1, 0, 1, 1},
					{1, 0, 0, 1, 0, 1, 1, 1, 1, 1}};
	print_sub_matrix(M);
	return (0);
}
