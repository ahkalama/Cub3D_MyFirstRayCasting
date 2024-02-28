/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:27:37 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/20 05:28:48 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

static	void	ft_draw_pixel(t_data *data, int x, int y, t_render *render)
{
	t_img	*img;
	int		color;

	if (ft_strchr(DOORS, data->map.map[(int)(render->wall_hit.y)]
		[(int)(render->wall_hit.x)]))
	{
		img = &data->map.door.img[ft_ll_find(data->map.ll_door,
				render->wall_hit.x, render->wall_hit.y)];
	}
	else if (render->direction == 'h' && render->angle < M_PI)
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
	if (ft_strchr(WALLS, data->map.map[(int)(render->wall_hit.y)]
		[(int)(render->wall_hit.x)]))
		data->map.depth[x] = render->distance;
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
