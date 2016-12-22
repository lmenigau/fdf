/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:53:20 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/21 08:21:42 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

void	plotline(int (*img)[1000], int x0, int y0, int x1, int y1);
void	plotline_octant(int (*img)[1000], int x0, int y0, int x1, int y1);
int		key_hook(int keycode, void *param);
int		expose_hook(void *param);
int		loop_hook(void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		ft_abs(int n);


#endif
