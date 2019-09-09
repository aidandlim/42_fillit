/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:46:38 by dlim              #+#    #+#             */
/*   Updated: 2019/06/15 14:28:44 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) > 0)
		ft_check_read(fd);
	else
		ft_putstr("error\n");
}

void	ft_check_read(int fd)
{
	char *structure;
	char *buffer;

	structure = ft_strnew(1);
	buffer = ft_strnew(1);
	while (read(fd, buffer, 1) > 0)
		structure = ft_strjoin(structure, buffer);
	free(buffer);
	if (structure[0] != '\0')
		ft_check_structure(structure);
	else
		ft_out_error(structure);
}

void	ft_check_structure(char *s)
{
	int result;
	int i;

	result = 1;
	if ((ft_strlen(s) - 20) % 21 != 0)
		result = 0;
	i = 0;
	while (s[i])
	{
		if ((i - i / 21) % 5 == 4)
		{
			if (s[i] != '\n')
				result = 0;
		}
		else
		{
			if (s[i] != '#' && s[i] != '.' && (i - i / 21) % 20 != 0)
				result = 0;
		}
		i++;
	}
	if (result)
		ft_transform_structure(s);
	else
		ft_out_error(s);
}

void	ft_check_blocks(char **blocks, int count)
{
	int i;

	i = 0;
	while (blocks[i])
	{
		if (!ft_check_block(blocks[i]))
		{
			ft_putstr("error\n");
			ft_util_doublepointer_free((void **)blocks, count);
			return ;
		}
		i++;
	}
	ft_fillit(blocks, count);
}

int		ft_check_block(char *block)
{
	int result;
	int count;
	int i;

	result = 0;
	count = 0;
	i = 0;
	while (block[i])
	{
		if (block[i] == '#')
			count++;
		if (i > 3 && block[i] == '#' && block[i - 4] == '#')
			result++;
		if (i < 12 && block[i] == '#' && block[i + 4] == '#')
			result++;
		if (i % 4 != 0 && block[i] == '#' && block[i - 1] == '#')
			result++;
		if (i % 4 != 3 && block[i] == '#' && block[i + 1] == '#')
			result++;
		i++;
	}
	if (count == 4 && (result == 6 || result == 8))
		return (1);
	else
		return (0);
}
