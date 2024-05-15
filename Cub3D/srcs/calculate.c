/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:20 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/23 14:11:47 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_distance(t_coordinates p1, t_coordinates p2)
{
	t_coordinates	distance;

	distance.x = powf(p2.x - p1.x, 2);
	distance.y = powf(p2.y - p1.y, 2);
	return (sqrtf(distance.x + distance.y));
}

int	ft_create_color(int transpancy, int r, int g, int b)
{
	return (transpancy << 24 | r << 16 | g << 8 | b);
}

double	ft_update_radian(double radian, double inc)
{
	radian += inc;
	if (radian > 2 * M_PI)
		radian -= 2 * M_PI;
	else if (radian < 0)
		radian += 2 * M_PI;
	return (radian);
}

double	ft_deg_to_rad(double degree)
{
	return ((degree * M_PI) / 180.0);
}
