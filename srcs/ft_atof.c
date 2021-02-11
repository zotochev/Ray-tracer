/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:25:13 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:27:42 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

double		ft_atof(const char *str)
{
	double	exponent;
	double	fraction;
	char	*str_p;
	double	flag;

	exponent = (double)ft_atoi(str);
	fraction = 0;
	str_p = (char *)str;
	flag = 1;
	while (*str_p && (ft_isspace(*str_p) || (*str_p == '-' || *str_p == '+')))
	{
		if (*str_p == '-')
			flag = -1;
		str_p++;
	}
	while (*str_p && ft_isdigit(*str_p))
		str_p++;
	if (*str_p == '.')
		fraction = (double)ft_atoi(++str_p);
	while (*str_p && *str_p >= '0' && *str_p++ <= '9')
		fraction /= 10;
	return (exponent + (fraction * flag));
}

int			atoresolution(const char *str, int max_num)
{
	int	num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= 48 && *str <= 57 && num < max_num)
		num = num * 10 + (*str++ - 48);
	if (num > max_num)
		return (max_num);
	return (num);
}

t_vector	ft_atovector(const char *line)
{
	t_vector	vector;
	char		*line_p;

	line_p = (char *)line;
	vector.x = ft_atof(line_p);
	line_p += ft_skip_float(line_p);
	if (*line_p == ',')
		vector.y = ft_atof(++line_p);
	line_p += ft_skip_float(line_p);
	if (*line_p == ',')
		vector.z = ft_atof(++line_p);
	return (vector);
}

int			ft_skip_float(const char *line)
{
	int		count;
	char	*line_p;

	count = 0;
	line_p = (char *)line;
	while (*line_p &&
			(*line_p == '+'
			|| *line_p == '-'
			|| ft_isspace(*line_p)))
	{
		line_p++;
		count++;
	}
	while (*line_p &&
			(ft_isdigit(*line_p)
			|| *line_p == '.'))
	{
		line_p++;
		count++;
	}
	return (count);
}

int			ft_skip_vector(const char *line)
{
	char	*line_p;

	line_p = (char *)line;
	while (ft_isspace(*line_p))
		line_p++;
	line_p += ft_skip_float(line_p);
	while (ft_isspace(*line_p) || *line_p == ',')
		line_p++;
	line_p += ft_skip_float(line_p);
	while (ft_isspace(*line_p) || *line_p == ',')
		line_p++;
	line_p += ft_skip_float(line_p);
	while (ft_isspace(*line_p))
		line_p++;
	return ((int)(line_p - line));
}
