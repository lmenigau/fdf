/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/24 01:32:39 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_tmp {
	t_m44	mat;
}				t_tmp;

t_m44p	mat_mult(int b, t_m44 *mat)
{
	t_m44p	mat2;
	struct	s_tmp *tmp;
	int		n;

	n = 4;
	tmp = (struct s_tmp) {{{0, 0, 0, 0},
						  {0, n * b, 0, 0},
						  {0, 0, 0, 0},
						  {0, 0, 0, 0}}};
	*mat = tmp;
	//mat2 = malloc(sizeof(t_m44));
	//memcpy(mat2, mat, sizeof(t_m44));
	return (mat2);
}

int		main(void)
{
	t_m44 mat;

	mat_mult(3, &mat);
	printf("%f\n", mat.mat[1][1]);
	printf("%f\n", 56546.2695);
	printf("%f\n", mat.mat[1][1]);
	printf("%zu", sizeof(float[4][4]));
}
