/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:52:30 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/21 02:13:59 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plotline(int (*img)[1000], int x0, int y0, int x1, int y1)
{

		plotline_octant(img, x0, y0, x1, y1);
}

void	plotline_octant(int (*img)[1000], int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	int		fsp;

	fsp = 0;
	if (x1 < y1)
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
		fsp = 1;
	}
	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx;
	x =	x0;
	y = y0;
	while (x < x1)
	{
		if (fsp)
			img[x][y] = 0x00FFFFFF;
		else
			img[y][x] = 0x00FFFFFF;
		mlx_put_image_to_window(mlx_ptr, window, img_ptr,0, 0);
		if (d > 0)
		{
			y++;
			d = d - dx;
		}
		d = d + dy;
		x++;
	}
}


