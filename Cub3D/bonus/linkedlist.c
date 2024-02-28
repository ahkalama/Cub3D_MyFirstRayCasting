/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:36:51 by sekilinc          #+#    #+#             */
/*   Updated: 2024/02/26 17:21:35 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"
#include "../includes_bonus/structs.h"

void	add_list_back(t_sprites **lst, t_sprites *sprite)
{
	t_sprites	*tmp;

	if (!(*lst))
	{
		(*lst) = sprite;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = sprite;
}

t_sprites	*new_sprite(t_data *data, char *name, char *location)
{
	int			a;
	t_sprites	*sprite;

	sprite = malloc(sizeof(t_sprites));
	if (!sprite)
		return (NULL);
	sprite->image = mlx_xpm_file_to_image(data->mlx.ptr, location, &a, &a);
	sprite->x = 0;
	sprite->y = 0;
	sprite->name = name;
	sprite->next = NULL;
	return (sprite);
}
