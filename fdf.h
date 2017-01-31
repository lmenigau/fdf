/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:53:20 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/31 03:11:58 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# include <math.h>

# include "libft/libft.h"
# include "get_next_line.h"
# include "matrix.h"

#define		WIN_WIDTH	1920
#define		WIN_HEIGHT	1080

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_line
{
	t_vec2		p1;
	t_vec2		p2;
}				t_line;

typedef struct	s_gstate
{
	int			(*imgmem)[WIN_WIDTH];
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void		*mlx_ptr;
	void		*window;
	void		*img_ptr;
	t_vec3		**map;
	int			map_size;
	t_list		*head;
}				t_gstate;

void			plotline(int (*img)[WIN_WIDTH], int x0, int y0, int x1, int y1);
void			plotline_octant(int (*img)[WIN_WIDTH], int x0, int y0, int x1, int y1);
int				key_hook(int keycode, void *param);
int				expose_hook(void *param);
int				loop_hook(void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				motion_hook(int button, int x, int y, void *param);
int				ft_abs(int n);

void	plotline_octant_vec(int (*img)[WIN_WIDTH], t_vec2 p0, t_vec2 p1, int fsp);
void	plotline_vec(int (*img)[WIN_WIDTH], t_vec2 p0, t_vec2 p1);
#endif
