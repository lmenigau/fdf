/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/21 09:37:34 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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


int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	variousttest(int (*imgmem)[1000])
{
	imgmem[50][50] = 0x00F1FFFF;
	plotline(imgmem, 400, 10, 130, 200);
	plotline(imgmem, 200, 10, 300, 130);
	plotline(imgmem, 100, 10, 300, 130);
	plotline(imgmem, 100, 10, 130, 300);
	plotline(imgmem, 0, 0, 300, 300);
	plotline(imgmem, 500, 0, 0, 500);
	plotline(imgmem, 500, 0, 0, 300);
}

int		**parse_file(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		**map;
	char	**tab;
	int		i;
	int		j;

	map = malloc(sizeof(*map) * 1000);
	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = malloc(sizeof (**map) * ft_strlen(line));
		tab = ft_strsplit(line, ' ');
		j = 0;
		while (tab[j])
		{
			map[i][j] = ft_atoi(tab[j]);
			j++;
		}
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	int		(*imgmem)[1000];
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*mlx_ptr;
	void	*window;
	void	*img_ptr;
	int		**map;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1920, 1080, "fdf");
	mlx_key_hook(window, key_hook, NULL);
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	bits_per_pixel = 32;
	size_line = 1000;
	endian = 1;
	imgmem = (int (*)[1000])mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	map = parse_file(argc, argv);
	mlx_put_image_to_window(mlx_ptr, window, img_ptr,0, 0);
	mlx_mouse_hook(window, mouse_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
