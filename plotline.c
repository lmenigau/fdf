/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:52:30 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/31 03:36:58 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void plot(int (*img)[WIN_WIDTH], int x, int y, int fsp)
{
	if (fsp == 1)
		ft_swap(&x, &y);
	x = ft_abs(x);
	y = ft_abs(y);
	img[y][x] = 0x00FFFFFF;
}
void	plotline(int (*img)[WIN_WIDTH], int x0, int y0, int x1, int y1)
{
		plotline_octant(img, x0, y0, x1, y1);
}

void	plotline_octant_vec(int (*img)[WIN_WIDTH], t_vec2 p0, t_vec2 p1, int fsp)
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	d = 2 * dy - dx;
	x =	p0.x;
	y = p0.y;
	while (x < p1.x)
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

void	plotline_vec(int (*img)[WIN_WIDTH], t_vec2 p0, t_vec2 p1)
{
	int		fsp;

	fsp = 0;
	if (p0.x > p1.x)
	{
		p0.x = -p0.x;
		p1.x = -p1.x;
	}
	if (p1.x - p0.x < p1.y - p0.y)
	{
		ft_swap(&p0.x, &p0.y);
		ft_swap(&p1.x, &p1.y);
		fsp = 1;
	}
	if (p0.x > p1.x && p0.y > p1.y)
		plotline_octant_vec(img, p0, p1, fsp);
	else
		plotline_octant_vec(img, p1, p0, fsp);
}

void	plotline_octant(int (*img)[WIN_WIDTH], int x0, int y0, int x1, int y1)
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
