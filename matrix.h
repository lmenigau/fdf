/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:57:51 by lmenigau          #+#    #+#             */
/*   Updated: 2017/02/03 18:35:21 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef	float	(*t_m44p)[4];
typedef	float	t_m44[4][4];

typedef struct	s_m44
{
	t_m44	mat;
}				t_m44st;

t_m44st			mat_mult(t_m44p l, t_m44p r);
t_m44st			mat_array_mult(t_m44 *mat_array, int length);
void			print_mat(t_m44p mat);
#endif
