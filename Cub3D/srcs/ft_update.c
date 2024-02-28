/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:19:24 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/18 18:28:59 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_update(t_data *data)
{
	t_render	*r;
	t_list		*ll_render;

	r = NULL;
	ll_render = NULL;
	ft_move_player(data);
	ft_render(data, 0.0, r, ll_render);
	mlx_put_image_to_window(data->mlx.ptr,
		data->mlx.win, data->mlx.img.img, 0, 0);
	ft_car_driving(data);
	return (0);
}
