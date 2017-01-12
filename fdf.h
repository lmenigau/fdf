/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:53:20 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/12 18:12:14 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# include <math.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_line
{
	t_vec2		p1;
	t_vec2		p2;
}				t_line;

void			plotline(int (*img)[1000], int x0, int y0, int x1, int y1);
void			plotline_octant(int (*img)[1000], int x0, int y0, int x1, int y1);
int				key_hook(int keycode, void *param);
int				expose_hook(void *param);
int				loop_hook(void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				ft_abs(int n);


#endif
