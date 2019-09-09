/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:57:55 by dlim              #+#    #+#             */
/*   Updated: 2019/06/15 15:20:40 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	if (argc != 2)
		ft_putstr("Usage: ./fillit source_file\n");
	else
		ft_check_file(argv[1]);
	return (0);
}

void	ft_output(char *frame, int size)
{
	int i;

	i = 0;
	while (frame[i])
	{
		ft_putchar(frame[i]);
		if (i % size == size - 1)
			ft_putstr("\n");
		i++;
	}
	free(frame);
}

void	ft_out_error(char *structure)
{
	free(structure);
	ft_putstr("error\n");
}
