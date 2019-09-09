/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:46:57 by dlim              #+#    #+#             */
/*   Updated: 2019/06/15 15:05:54 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(char **blocks, int count)
{
	int		**iblocks;
	char	*frame;
	int		size;
	int		*sp;

	sp = (int *)malloc(sizeof(int) * 2);
	iblocks = NULL;
	frame = NULL;
	size = ft_util_sqrt(count * 4);
	while (1)
	{
		sp[0] = count;
		sp[1] = size;
		iblocks = ft_transform_blocks_integer(iblocks, blocks, count);
		frame = ft_set_frame(frame, size);
		if (ft_solve(iblocks, frame, 0, sp))
			break ;
		size++;
	}
	free(sp);
	ft_util_doublepointer_free((void **)blocks, count);
	ft_util_doublepointer_free((void **)iblocks, count);
	ft_output(frame, size);
}

char	*ft_set_frame(char *frame, int size)
{
	if (frame)
		free(frame);
	frame = (char *)malloc(sizeof(char) * (size * size + 1));
	ft_memset(frame, '.', size * size);
	frame[size * size] = '\0';
	return (frame);
}

int		ft_solve(int **iblocks, char *frame, int i, int *sp)
{
	int		j;
	int		*up;

	if (i == sp[0])
		return (1);
	up = (int *)malloc(sizeof(int) * 2);
	j = 0;
	while (j < sp[1] * sp[1])
	{
		up[0] = i;
		up[1] = j;
		if (ft_util_possible(iblocks, frame, up, sp[1]))
		{
			ft_util_fix(iblocks, frame, up, sp[1]);
			if (ft_solve(iblocks, frame, i + 1, sp))
			{
				free(up);
				return (1);
			}
			ft_util_cleaner(iblocks, frame, up, sp[1]);
		}
		j++;
	}
	free(up);
	return (0);
}

void	ft_util_fix(int **iblocks, char *frame, int *up, int size)
{
	frame[up[1] + iblocks[up[0]][0]] = 'A' + up[0];
	frame[up[1] + iblocks[up[0]][1] + ((iblocks[up[0]][1]) / 4 -
		(iblocks[up[0]][0]) / 4) * (size - 4)] = 'A' + up[0];
	frame[up[1] + iblocks[up[0]][2] + ((iblocks[up[0]][2]) / 4 -
		(iblocks[up[0]][0]) / 4) * (size - 4)] = 'A' + up[0];
	frame[up[1] + iblocks[up[0]][3] + ((iblocks[up[0]][3]) / 4 -
		(iblocks[up[0]][0]) / 4) * (size - 4)] = 'A' + up[0];
}

int		ft_util_possible(int **iblocks, char *frame, int *up, int size)
{
	int		x;

	x = ft_util_xsize(iblocks[up[0]][0], iblocks[up[0]][1],
		iblocks[up[0]][2], iblocks[up[0]][3]);
	if (up[1] % size + x < size && size * size > up[1] + iblocks[up[0]][3] +
		((iblocks[up[0]][3]) / 4 - (iblocks[up[0]][0]) / 4) * (size - 4))
	{
		if (frame[up[1] + iblocks[up[0]][0]] == '.' &&
			frame[up[1] + iblocks[up[0]][1] + ((iblocks[up[0]][1]) /
				4 - (iblocks[up[0]][0]) / 4) * (size - 4)] == '.' &&
			frame[up[1] + iblocks[up[0]][2] + ((iblocks[up[0]][2]) /
				4 - (iblocks[up[0]][0]) / 4) * (size - 4)] == '.' &&
			frame[up[1] + iblocks[up[0]][3] + ((iblocks[up[0]][3]) /
				4 - (iblocks[up[0]][0]) / 4) * (size - 4)] == '.')
			return (1);
	}
	return (0);
}
