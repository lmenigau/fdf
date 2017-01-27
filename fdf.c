/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/27 08:26:36 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		parse_file(int argc, char **argv, t_vec3 ***map)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;
	int		j;

	*map = malloc(sizeof(**map) * 1000);
	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		(*map)[i] = malloc(sizeof (***map) * ft_strlen(line));
		tab = ft_strsplit(line, ' ');
		j = 0;
		while (tab[j])
		{
			(*map)[i][j].z = ft_atoi(tab[j]);
			(*map)[i][j].x = j;
			(*map)[i][j].y = i;
			j++;
		}
		i++;
	}
	(*map)[i] = NULL;
	return (j);
}


t_vec2	point_transform(t_vec3 pt, t_m44p m, t_vec2 point)
{
	point.x = pt.x * m[0][0] + pt.y * m[1][0] + pt.z * m[2][0] + m[3][0];
	point.y = pt.x * m[0][1] + pt.y * m[1][1] + pt.z * m[2][1] + m[3][1];

	return point;
}

t_vec2	 **project(t_vec3 **map, int map_size)
{
	int		x;
	int		y;
	int		**t_vec2;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (x < map_size)
		{
			x++;
		}
		y++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	t_vec2	**proj;
	t_gstate gstate;

	gstate.mlx_ptr = mlx_init();
	gstate.window = mlx_new_window(gstate.mlx_ptr, 1920, 1080, "fdf");
	mlx_key_hook(gstate.window, key_hook, NULL);
	gstate.img_ptr = mlx_new_image(gstate.mlx_ptr, 1000, 1000);
	gstate.imgmem = (int (*)[1000])mlx_get_data_addr(gstate.img_ptr, &gstate.bits_per_pixel, &gstate.size_line, &gstate.endian);
	gstate.map_size = parse_file(argc, argv, &gstate.map);
	proj = project(gstate.map, gstate.map_size);
	mlx_put_image_to_window(gstate.mlx_ptr, gstate.window, gstate.img_ptr,0, 0);
	mlx_mouse_hook(gstate.window, mouse_hook, NULL);
	mlx_hook(gstate.window, 6, 0, motion_hook, NULL);
	mlx_loop(gstate.mlx_ptr);
	return (0);
}
