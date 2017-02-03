/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:51:35 by lmenigau          #+#    #+#             */
/*   Updated: 2017/02/03 18:11:25 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		key_hook(int keycode, t_gstate *gstate)
{
	printf("key:%d\n", keycode);
	mlx_do_key_autorepeaton(gstate->mlx_ptr);
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		gstate->tr.x += 10;
	else if (keycode == 124)
		gstate->tr.x -= 10;
	else if (keycode == 125)
		gstate->tr.y -= 10;
	else if (keycode == 126)
		gstate->tr.y += 10;
	else if (keycode == 38)
		gstate->zoom.z *= 1.10;
	else if (keycode == 40)
		gstate->zoom.z *= 0.90;
	map_render(gstate->map, gstate->line_count, gstate);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_gstate *gstate)
{
	printf("button: %d, x: %d, y: %d\n", button, x, y);
	if (button == 5)
	{
		gstate->zoom.x *= 1.10;
		gstate->zoom.y *= 1.10;
		gstate->zoom.z *= 1.10;
	}
	else if (button == 4)
	{
		gstate->zoom.x *= 0.90;
		gstate->zoom.y *= 0.90;
		gstate->zoom.z *= 0.90;
	}
	map_render(gstate->map, gstate->line_count, gstate);
	return (0);
}

int		motion_hook(int x, int y, t_gstate *gstate)
{
		printf("x: %d, y: %d\n", x, y);
		gstate->angle.z = ((float)x - WIN_WIDTH / 2) / WIN_WIDTH * 2 * M_PI;
		gstate->angle.x = ((float)y - WIN_HEIGHT / 2) / WIN_HEIGHT *  2 *M_PI;
		map_render(gstate->map, gstate->line_count, gstate);
		return (0);
}

