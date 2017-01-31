/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:51:35 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/31 09:44:46 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	printf("key:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose_hook(void *param)
{
	printf("log expose event\n");
	return (0);
}

int		loop_hook(void *param)
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

int		motion_hook(int x, int y, t_gstate *gstate)
{
		printf("x: %d, y: %d\n", x, y);
		gstate->angle.z = ((float)x - WIN_WIDTH / 2) / WIN_WIDTH * M_PI;
		gstate->angle.x = ((float)y - WIN_HEIGHT / 2) / WIN_HEIGHT * M_PI;
		map_render(gstate->map, gstate->line_count, gstate);
		return (0);
}

