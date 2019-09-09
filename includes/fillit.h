/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:58:01 by dlim              #+#    #+#             */
/*   Updated: 2019/06/02 16:10:16 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

int		main(int argc, char *argv[]);
void	ft_output(char *frame, int size);
void	ft_out_error(char *structure);
void	ft_check_file(char *file);
void	ft_check_read(int fd);
void	ft_check_structure(char *structure);
void	ft_check_blocks(char **blocks, int count);
int		ft_check_block(char *block);
void	ft_transform_structure(char *structure);
void	*ft_transform_blocks_integer(int **iblocks, char **blocks, int count);
void	*ft_transform_blocks_shift(int **iblocks, int count);
void	ft_fillit(char **blocks, int count);
char	*ft_set_frame(char *frame, int size);
int		ft_solve(int **iblocks, char *frame, int i, int *p);
void	ft_util_cleaner(int **iblocks, char *frame, int *up, int size);
int		ft_util_sqrt(int count);
int		ft_util_xsize(int a, int b, int c, int d);
int		ft_util_leftest(int a, int b, int c, int d);
void	ft_util_fix(int **iblocks, char *frame, int *up, int size);
int		ft_util_possible(int **iblocks, char *frame, int *up, int size);
void	ft_util_doublepointer_free(void **p, int count);

#endif
