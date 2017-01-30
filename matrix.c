/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/27 12:23:59 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	mat_mult(t_m44p res, t_m44p l, t_m44p r)
{
	int		i;
	int		j;

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
			printf("%4.0f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_vec2	point_transform(t_vec3 pt, t_m44p m, t_vec2 point)
{
	point.x = pt.x * m[0][0] + pt.y * m[1][0] + pt.z * m[2][0] + m[3][0];
	point.y = pt.x * m[0][1] + pt.y * m[1][1] + pt.z * m[2][1] + m[3][1];

	return point;
}

/*int		main(void)
{
	t_m44p	mat;
	t_m44p	mat2;
	t_m44	res;
	int		n;

	n = 4;
	mat = (t_m44){	{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}};

	mat2 = (t_m44){	{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}};
	mat_mult(res, mat, mat2);
	print_mat(res);
	printf("%f\n", mat[1][1]);
	printf("%f\n", 56546.2695);
	printf("%f\n", mat[1][1]);
	printf("%zu", sizeof(float[4][4]));
}*/
