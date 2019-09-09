/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:46:45 by dlim              #+#    #+#             */
/*   Updated: 2019/06/02 16:24:26 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_transform_structure(char *structure)
{
	char	**blocks;
	char	*result;
	char	*buffer;
	int		i;

	i = 0;
	result = ft_strnew(1);
	buffer = ft_strnew(1);
	while (structure[i])
	{
		if (structure[i] != '\n' || structure[i - 1] == '\n')
		{
			buffer[0] = structure[i];
			result = ft_strjoin(result, buffer);
		}
		i++;
	}
	blocks = ft_strsplit(result, '\n');
	ft_check_blocks(blocks, ft_strlen(result) / 17 + 1);
	free(buffer);
	free(structure);
	free(result);
}

void	*ft_transform_blocks_integer(int **iblocks, char **blocks, int count)
{
	int		i;
	int		j;
	int		k;

	if (iblocks)
		ft_util_doublepointer_free((void **)iblocks, count);
	iblocks = (int **)malloc(sizeof(int *) * count);
	i = 0;
	while (i < count)
	{
		j = 0;
		k = 0;
		iblocks[i] = (int *)malloc(sizeof(int) * 5);
		iblocks[i][4] = 0;
		while (blocks[i][j])
		{
			if (blocks[i][j] == '#')
				iblocks[i][k++] = j;
			j++;
		}
		i++;
	}
	ft_transform_blocks_shift(iblocks, count);
	return (iblocks);
}

void	*ft_transform_blocks_shift(int **iblocks, int count)
{
	int		i;
	int		x;

	i = 0;
	while (i < count)
	{
		x = ft_util_leftest(iblocks[i][0], iblocks[i][1],
			iblocks[i][2], iblocks[i][3]);
		iblocks[i][3] = iblocks[i][3] - iblocks[i][0] + x;
		iblocks[i][2] = iblocks[i][2] - iblocks[i][0] + x;
		iblocks[i][1] = iblocks[i][1] - iblocks[i][0] + x;
		iblocks[i][0] = x;
		i++;
	}
	return (iblocks);
}
