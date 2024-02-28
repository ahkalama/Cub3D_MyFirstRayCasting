/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_car_driving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:22:24 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/27 15:36:17 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	ft_car_driving(t_data *data)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx.ptr, "textures/car.xpm",
			&img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("Error: Failed to load XPM file\n", 2);
		return (1);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, img.img, 0, 0);
	return (0);
}

int	ft_car_left(t_data *data)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx.ptr, "textures/carleft.xpm",
			&img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("Error: Failed to load XPM file\n", 2);
		return (1);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, img.img, 0, 0);
	return (0);
}

int	ft_car_right(t_data *data)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx.ptr, "textures/carright.xpm",
			&img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("Error: Failed to load XPM file\n", 2);
		return (1);
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, img.img, 0, 0);
	return (0);
}
