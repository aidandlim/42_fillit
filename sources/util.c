/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:47:31 by dlim              #+#    #+#             */
/*   Updated: 2019/06/02 14:16:44 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_util_cleaner(int **iblocks, char *frame, int *up, int size)
{
	frame[up[1] + iblocks[up[0]][0]] = '.';
	frame[up[1] + iblocks[up[0]][1] + ((iblocks[up[0]][1]) /
		4 - (iblocks[up[0]][0]) / 4) * (size - 4)] = '.';
	frame[up[1] + iblocks[up[0]][2] + ((iblocks[up[0]][2]) /
		4 - (iblocks[up[0]][0]) / 4) * (size - 4)] = '.';
	frame[up[1] + iblocks[up[0]][3] + ((iblocks[up[0]][3]) /
		4 - (iblocks[up[0]][0]) / 4) * (size - 4)] = '.';
}

int		ft_util_sqrt(int count)
{
	int	i;

	i = 1;
	while (count > i * i)
		i++;
	return (i);
}

int		ft_util_xsize(int a, int b, int c, int d)
{
	int max;
	int min;

	max = a % 4;
	min = a % 4;
	if (max < b % 4)
		max = b % 4;
	if (max < c % 4)
		max = c % 4;
	if (max < d % 4)
		max = d % 4;
	if (min > b % 4)
		min = b % 4;
	if (min > c % 4)
		min = c % 4;
	if (min > d % 4)
		min = d % 4;
	return (max - min);
}

int		ft_util_leftest(int a, int b, int c, int d)
{
	int	i;

	i = a % 4;
	if (i > b % 4)
		i = b % 4;
	if (i > c % 4)
		i = c % 4;
	if (i > d % 4)
		i = d % 4;
	return (a % 4 - i);
}

void	ft_util_doublepointer_free(void **p, int count)
{
	int i;

	if (p)
	{
		i = 0;
		while (i < count)
		{
			free(p[i]);
			i++;
		}
		free(p);
	}
}
