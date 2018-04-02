/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 09:03:21 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/01 13:52:15 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

int		get_depth(char *num)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (num[i] <= '9' && num[i] >= '0')
		n = (n * 10) + (num[i++] - '0');
	return (n);
}

void	*ft_malloc(int size)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		return (ft_malloc(size));
	return (ptr);
}
