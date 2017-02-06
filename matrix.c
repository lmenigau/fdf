/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/02/06 09:56:30 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_m44st	mat_mult(t_m44p l, t_m44p r)
{
	t_m44st	resst;
	t_m44p	res;
	int		i;
	int		j;

	res = resst.mat;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = l[i][0] * r[0][j] + l[i][1] * r[1][j] + l[i][2] *
				r[2][j] + l[i][3] * r[3][j];
			j++;
		}
		i++;
	}
	return (resst);
}

t_m44st	mat_array_mult(t_m44 *mat_array, int length)
{
	int		i;
	t_m44st acc;

	acc = mat_mult(mat_array[0], mat_array[1]);
	i = 2;
	while (i < length)
	{
		acc = mat_mult(acc.mat, mat_array[i]);
		i++;
	}
	return (acc);
}

void	print_mat(t_m44p mat)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%4.2f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_vec2	point_transform(t_vec3 pt, t_m44p m)
{
	t_vec2	res;

	res.x = pt.x * m[0][0] + pt.y * m[1][0] + pt.z * m[2][0] + m[3][0];
	res.y = pt.x * m[0][1] + pt.y * m[1][1] + pt.z * m[2][1] + m[3][1];
	if (res.x < 0 || res.y < 0 || res.x >= WIN_WIDTH || res.y >= WIN_HEIGHT)
		res.x = -1;
	return (res);
}

t_m44st	matrix_build(int line_count, int **map, t_gstate *gstate)
{
	t_m44	*mat_arr;

	mat_arr = (t_m44[5]){
					{	{1, 0, 0, 0},
						{0, 1, 0, 0},
						{0, 0, 1, 0},
						{-map[0][0] / (float)2, -line_count / (float)2, 0, 1}},
					{	{gstate->zoom.x, 0, 0, 0},
						{0, gstate->zoom.y, 0, 0},
						{0, 0, gstate->zoom.z, 0},
						{0, 0, 0, 1}},
					{	{cos(gstate->angle.z), sin(gstate->angle.z), 0, 0},
						{-sin(gstate->angle.z), cos(gstate->angle.z), 0, 0},
						{0, 0, 1, 0},
						{0, 0, 0, 1}},
					{	{1, 0, 0, 0},
						{0, cos(gstate->angle.x), -sin(gstate->angle.x), 0},
						{0, sin(gstate->angle.x), cos(gstate->angle.x), 0},
						{0, 0, 0, 1}},
					{	{1, 0, 0, 0},
						{0, 1, 0, 0},
						{0, 0, 1, 0},
						{WIN_WIDTH / (float)2 + gstate->tr.x, WIN_HEIGHT / (float)2 +
							gstate->tr.y, 0, 1}}};
	return (mat_array_mult(mat_arr, 5));
}
