/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:47 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/19 17:37:26 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_images(t_data *data)
{
	data->mlx.img.img = mlx_new_image(data->mlx.ptr,
			WIDTH, HEIGHT);
	if (!data->mlx.img.img)
		return (printf("Error\nCouldn't initilize window.\n"), 0);
	data->mlx.img.get_addr = (int *)mlx_get_data_addr(data->mlx.img.img,
			&data->mlx.img.bits_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.steps);
	return (1);
}
