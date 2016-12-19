/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/19 21:12:20 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int		key_hook(int keycode, void *param)
{
	printf("key:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		draw_rectangle(int (*rect)[1000], int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			rect[i][j] = color;
			j++;
		}
		i++;
	}
	return (0);
}
int		 expose_hook(void *param)
{
	printf("log expose event\n");
	return (0);
}

int		 loop_hook(void *param)
{
	static int i  = 0;
	printf("no fucking event #%dbitch\n", i);
	i++;
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	printf("button: %d, x: %d, y: %d\n", button, x, y);
	return (0);
}

void	plotline(int (*img)[1000], int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;

	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx;
	x =	x0;
	y = y0;
	while (x < x1)
	{
		img[y][x] = 0x00FFFFFF;
		printf("%d\n", d);
		if (d > 0)
		{
			y++;
			d = d - dx;
		}
		d = d + dy;
		x++;
	}
}

int		main()
{
	void	*mlx_ptr;
	void	*window;
	void	*img_ptr;
	int		(*imgmem)[1000];
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
	mlx_key_hook(window, key_hook, NULL);
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	bits_per_pixel = 32;
	size_line = 1000;
	endian = 1;
	imgmem = (int (*)[1000])mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	imgmem[50][50] = 0x00F1FFFF;
	draw_rectangle((int (*)[1000])&imgmem[50][50], 100, 100, 0x00FF0000);
	draw_rectangle((int (*)[1000])&imgmem[250][50], 50, 10, 0x00FF0000);
	plotline(imgmem, 10, 10, 500, 500);
	plotline(imgmem, 10, 40, 425, 50);
	mlx_put_image_to_window(mlx_ptr, window, img_ptr,0, 0);
	//mlx_expose_hook(window, expose_hook, NULL);
	mlx_mouse_hook(window, mouse_hook, NULL);
	//mlx_loop_hook(mlx_ptr, loop_hook, NULL);
	mlx_string_put(mlx_ptr, window, 500, 500, 0x00FFFFFF, "hijo de puta");
	mlx_loop(mlx_ptr);
	return (0);
}
