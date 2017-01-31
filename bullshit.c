/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 08:22:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/31 03:14:38 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_rectangle(int (*rect)[WIN_WIDTH], int x, int y, int color)
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
void	variousttest(int (*imgmem)[WIN_WIDTH])
{
	imgmem[50][50] = 0x00F1FFFF;
	plotline(imgmem, 400, 10, 130, 200);
	plotline(imgmem, 20, 10, 300, 130);
	plotline(imgmem, 100, 10, 300, 130);
	plotline(imgmem, 100, 10, 130, 300);
	plotline(imgmem, 0, 0, 300, 300);
	plotline(imgmem, 500, 0, 0, 500);
	plotline(imgmem, 500, 0, 0, 300);
}

void	variousttest_vec(int (*imgmem)[WIN_WIDTH])
{
	imgmem[50][50] = 0x00F1FFFF;
	plotline_vec(imgmem, (t_vec2) {400, 10},(t_vec2) {130, 200});
	plotline_vec(imgmem, (t_vec2) {20, 10}, (t_vec2) {300, 130});
	plotline_vec(imgmem, (t_vec2) {100, 10}, (t_vec2) {300, 130});
	plotline_vec(imgmem, (t_vec2) {100, 10}, (t_vec2) {130, 300});
	plotline_vec(imgmem, (t_vec2) {0, 0}, (t_vec2) {300, 300});
	plotline_vec(imgmem, (t_vec2) {500, 0}, (t_vec2) {0, 500});
	plotline_vec(imgmem, (t_vec2) {500, 0}, (t_vec2) {0, 300});
}


void	debugtest(t_gstate *gstate)
{
	printf("%d\n", gstate->size_line);
	variousttest(gstate->imgmem);
}
