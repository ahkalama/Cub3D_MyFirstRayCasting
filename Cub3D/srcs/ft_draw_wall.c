/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:18:31 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/22 13:56:25 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_draw_pixel(t_data *data, int x, int y, t_render *render)
{
	t_img	*img;
	int		color;

	(void)x;
	(void)y;
	if (render->direction == 'h' && render->angle < M_PI)
		img = &data->map.north;
	else if (render->direction == 'h' && render->angle < 2.0 * M_PI)
		img = &data->map.south;
	else if (render->direction == 'v'
		&& (render->angle < M_PI_2 || render->angle > M_PI_2 * 3.0))
		img = &data->map.west;
	else
		img = &data->map.east;
	color = 0;
	if (color != ft_create_color(255, 0, 0, 0))
		data->mlx.img.get_addr[y * WIDTH + x] = color;
}

void	ft_draw_wall(t_data *data, t_list *ll_render)
{
	int			x;
	int			y;
	t_render	*render;

	while (ll_render)
	{
		render = ll_render->data;
		render->y_tex = 0;
		y = (HEIGHT / 2) - (render->wall_dimen.height / 2);
		while (y < (HEIGHT / 2) + (render->wall_dimen.height / 2) && y < HEIGHT)
		{
			x = (render->degree / ROT_SPEED) * render->wall_dimen.width;
			while (x < ((render->degree / ROT_SPEED) * render->wall_dimen.width)
				+ render->wall_dimen.width && x < WIDTH)
			{
				ft_draw_pixel(data, x, y, render);
				x++;
			}
			(render->y_tex)++;
			y++;
		}
		ll_render = ll_render->next;
	}
}
