/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation_products.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:43:36 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:45:15 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

double		vector_dot(t_vector vector_1, t_vector vector_2)
{
	return (vector_1.x * vector_2.x
			+ vector_1.y * vector_2.y
			+ vector_1.z * vector_2.z);
}

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

double		vector_length(t_vector vector)
{
	return (sqrt(vector_dot(vector, vector)));
}

t_vector	vector_normalization(t_vector vector)
{
	return (vector_dev(vector, vector_length(vector)));
}
