/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:19:08 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:55 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_render(t_data *data, double degree, t_render	*r, t_list	*ll_render)
{
	while (degree <= FOV)
	{
		while (!ll_render || (ll_render && data->map.map
				[(int)((t_render *)(ll_render->data))->wall_hit.y]
				[(int)((t_render *)(ll_render->data))->wall_hit.x] != WALL))
		{
			r = malloc(1 * sizeof(t_render));
			if (!r)
				printf("Malloc failed");
			r->angle = ft_update_radian(data->player.angle,
					ft_deg_to_rad(degree - (FOV / 2.0)));
			if (!ll_render)
				ft_wall_dimension(data, r, data->player.pos, degree);
			else
				ft_wall_dimension(data, r,
					((t_render *)(ll_render->data))->wall_hit, degree);
			ll_add_head(&ll_render, ll_new(r));
		}
		ft_draw_wall(data, ll_render);
		ft_ll_clear(&ll_render);
		degree += ROT_SPEED;
	}
}
