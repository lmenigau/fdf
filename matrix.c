/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:22 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/24 16:17:42 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_tmp
{
	t_m44		mat;
}				t_tmp;

void	mat_mult(t_m44p res, t_m44p left, t_m44p right)
{
		int		i;
		int		j;

		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
			}
		}
}


int		main(void)
{
	t_m44p	mat;
	t_m44	res;
	int		n;

	n = 4;
	mat = (t_m44)	{{0, 0, 0, 0},
					{0, 0 , 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}};
	mat = (t_m44)	{{0, 0, 0, 0},
					{0, 0 , 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}};
	//mat_mult(3, &mat);
	printf("%f\n", mat[1][1]);
	printf("%f\n", 56546.2695);
	printf("%f\n", mat[1][1]);
	printf("%zu", sizeof(float[4][4]));
}

