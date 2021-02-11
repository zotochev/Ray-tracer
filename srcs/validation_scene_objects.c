/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_scene_objects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:35:01 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:35:21 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_plain_valid(char *plain)
{
	plain = plain + 2;
	if (!ft_isspace(*plain))
		return (0);
	while (ft_isspace(*plain))
		plain++;
	if (!is_beginning_of_num(plain) || !is_vector_valid(plain))
		return (0);
	plain += ft_skip_vector(plain);
	while (ft_isspace(*plain))
		plain++;
	if (!is_beginning_of_num(plain) || !is_vector_valid(plain))
		return (0);
	plain += ft_skip_vector(plain);
	while (ft_isspace(*plain))
		plain++;
	if (!is_beginning_of_num(plain) || !is_vector_valid(plain))
		return (0);
	plain += ft_skip_vector(plain);
	while (ft_isspace(*plain))
		plain++;
	return (*plain == '\0');
}

int	is_sphere_valid(char *sphere)
{
	return (is_light_valid(++sphere));
}

int	is_square_valid(char *square)
{
	square = square + 2;
	if (!ft_isspace(*square))
		return (0);
	while (ft_isspace(*square))
		square++;
	if (!is_beginning_of_num(square) || !is_vector_valid(square))
		return (0);
	square += ft_skip_vector(square);
	if (!is_beginning_of_num(square) || !is_vector_valid(square))
		return (0);
	square += ft_skip_vector(square);
	if (!(is_beginning_of_num(square)))
		return (0);
	square += ft_skip_float(square);
	while (ft_isspace(*square))
		square++;
	if (!is_beginning_of_num(square) || !is_vector_valid(square))
		return (0);
	square += ft_skip_vector(square);
	return (*square == '\0');
}

int	is_cylinder_valid(char *cylinder)
{
	cylinder = cylinder + 2;
	if (!ft_isspace(*cylinder))
		return (0);
	while (ft_isspace(*cylinder))
		cylinder++;
	if (!is_beginning_of_num(cylinder) || !is_vector_valid(cylinder))
		return (0);
	cylinder += ft_skip_vector(cylinder);
	if (!is_beginning_of_num(cylinder) || !is_vector_valid(cylinder))
		return (0);
	cylinder += ft_skip_vector(cylinder);
	if (!(is_beginning_of_num(cylinder)))
		return (0);
	cylinder += ft_skip_float(cylinder);
	while (ft_isspace(*cylinder))
		cylinder++;
	if (!(is_beginning_of_num(cylinder)))
		return (0);
	cylinder += ft_skip_float(cylinder);
	while (ft_isspace(*cylinder))
		cylinder++;
	if (!is_beginning_of_num(cylinder) || !is_vector_valid(cylinder))
		return (0);
	cylinder += ft_skip_vector(cylinder);
	return (*cylinder == '\0');
}

int	is_triangle_valid(char *triangle)
{
	triangle = triangle + 2;
	if (!ft_isspace(*triangle))
		return (0);
	while (ft_isspace(*triangle))
		triangle++;
	if (!is_beginning_of_num(triangle) || !is_vector_valid(triangle))
		return (0);
	triangle += ft_skip_vector(triangle);
	if (!is_beginning_of_num(triangle) || !is_vector_valid(triangle))
		return (0);
	triangle += ft_skip_vector(triangle);
	if (!is_beginning_of_num(triangle) || !is_vector_valid(triangle))
		return (0);
	triangle += ft_skip_vector(triangle);
	if (!is_beginning_of_num(triangle) || !is_vector_valid(triangle))
		return (0);
	triangle += ft_skip_vector(triangle);
	return (*triangle == '\0');
}
