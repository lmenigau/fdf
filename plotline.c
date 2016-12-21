/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:52:30 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/21 05:33:08 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plotline(int (*img)[1000], int x0, int y0, int x1, int y1)
{
		plotline_octant(img, x0, y0, x1, y1);
}

void plot(int (*img)[1000], int x, int y, int fsp)
{
	if (fsp == 1)
		ft_swap(&x, &y);
	x = ft_abs(x);
	y = ft_abs(y);
	img[y][x] = 0x00FFFFFF;
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
	if (x0 > x1)
	{
		x0 = -x0;
		x1 = -x1;
	}
	if (x1 - x0 < y1 - y0)
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
		plot(img, x, y, fsp);
		if (d > 0)
		{
			y++;
			d = d - dx;
		}
		d = d + dy;
		x++;
	}
}
