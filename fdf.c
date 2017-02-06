/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2017/02/06 12:14:29 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_proj(int **map, int line_count, t_gstate *gstate, t_m44p matrix)
{
	t_vec2	prev;
	t_vec2	curr;
	t_vec2	next;
	int		i;
	int		j;

	i = -1;
	while (++i < line_count)
	{
		prev = point_transform((t_vec3) {1, i, map[i][1]}, matrix);
		j = 1;
		while (++j <= map[i][0])
		{
			curr = point_transform((t_vec3) {j, i, map[i][j]}, matrix);
			if (curr.x != -1 && prev.x != -1 && j < map[i][0])
				plotline_vec(gstate->imgmem, prev, curr);
			if (i < line_count - 1 && j - 1 < map[i + 1][0])
				next = point_transform((t_vec3){j - 1, i + 1, map[i + 1][j -
						1]}, matrix);
			if (next.x != -1 && prev.x != -1 && i < line_count - 1
					&& j - 1 < map[i + 1][0])
				plotline_vec(gstate->imgmem, prev, next);
			prev = curr;
		}
	}
}

void	map_render(int **map, int line_count, t_gstate *gstate)
{
	t_m44p	matrix;

	gstate->img_ptr = mlx_new_image(gstate->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	gstate->imgmem = (int (*)[WIN_WIDTH])mlx_get_data_addr(gstate->img_ptr,
			&gstate->bits_per_pixel, &gstate->size_line, &gstate->endian);
	matrix = matrix_build(line_count - 1, map, gstate).mat;
	map_proj(map, line_count, gstate, matrix);
	mlx_put_image_to_window(gstate->mlx_ptr, gstate->window, gstate->img_ptr, 0,
			0);
	mlx_destroy_image(gstate->mlx_ptr, gstate->img_ptr);
}

int		main(int argc, char **argv)
{
	t_gstate	gstate;
	int			fd;

	if ((fd = open_file(argc, argv)) == -1)
		return (0);
	gstate.angle = (t_vec3) {0, 0, 0};
	gstate.tr = (t_vec2) {0, 0};
	if ((gstate.line_count = load_file(&gstate, fd)) == 0)
	{
		ft_putstr("empty file\n");
		return (0);
	}
	gstate.map = flaten_list(gstate.head, gstate.line_count);
	gstate.zoom = (t_vec3) {WIN_HEIGHT / (float)gstate.line_count,
		WIN_HEIGHT / (float)gstate.line_count, 200 / (float)gstate.line_count };
	gstate.mlx_ptr = mlx_init();
	gstate.window = mlx_new_window(gstate.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"fdf");
	mlx_do_key_autorepeaton(gstate.mlx_ptr);
	mlx_hook(gstate.window, 2, 0, key_hook, &gstate);
	map_render(gstate.map, gstate.line_count, &gstate);
	mlx_mouse_hook(gstate.window, mouse_hook, &gstate);
	mlx_hook(gstate.window, 6, 0, motion_hook, &gstate);
	mlx_loop(gstate.mlx_ptr);
	return (0);
}
