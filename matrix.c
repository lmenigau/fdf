/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/31 09:05:03 by lmenigau         ###   ########.fr       */
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

	acc  = mat_mult(mat_array[0], mat_array[1]);
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
	t_vec2	 point;
	point.x = pt.x * m[0][0] + pt.y * m[1][0] + pt.z * m[2][0] + m[3][0];
	point.y = pt.x * m[0][1] + pt.y * m[1][1] + pt.z * m[2][1] + m[3][1];

	return point;
}

/*int		main(void)
{
	t_m44p	mat;
	t_m44p	mat2;
	t_m44p	res;
	t_m44	*mat_arr;
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
	mat_arr = (t_m44[2]){
					{{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}}
					,
					{{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}}
	};
	res = mat_array_mult(mat_arr, 2).mat;
	//res = mat_mult(mat, mat2).mat;
	printf("%f\n", mat[1][1]);
	printf("%f\n", 56546.2695);
	printf("%f\n", mat[1][1]);
	printf("%zu\n", sizeof(float[4][4]));
	print_mat(res);
}*/
