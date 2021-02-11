/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:38:38 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:42:33 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_vector	vector_sum(t_vector vector_1, t_vector vector_2)
{
	t_vector	result;

	result.x = vector_1.x + vector_2.x;
	result.y = vector_1.y + vector_2.y;
	result.z = vector_1.z + vector_2.z;
	return (result);
}

t_vector	vector_sub(t_vector vector_1, t_vector vector_2)
{
	t_vector	result;

	result.x = vector_1.x - vector_2.x;
	result.y = vector_1.y - vector_2.y;
	result.z = vector_1.z - vector_2.z;
	return (result);
}

t_vector	vector_mul_by_scal(t_vector vector, double num)
{
	t_vector result;

	result.x = vector.x * num;
	result.y = vector.y * num;
	result.z = vector.z * num;
	return (result);
}

t_vector	vector_dev(t_vector vector, double num)
{
	t_vector	result;

	result.x = vector.x / num;
	result.y = vector.y / num;
	result.z = vector.z / num;
	return (result);
}
