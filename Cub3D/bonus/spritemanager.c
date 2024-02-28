/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritemanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:05:35 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 15:07:19 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

void	add_image(t_data *data, char *name, char *location)
{
	t_sprites	*sprite;
	t_sprites	*tmp;

	tmp = data->smanager.sprites;
	while (tmp)
	{
		if (tmp->name == name)
		{
			printf("this sprite already added : %s", name);
			return ;
		}
		tmp = tmp->next;
	}
	add_list_back(&data->smanager.sprites, sprite);
}

t_sprites	*get_image(t_data *data, char *name)
{
	t_sprites	*tmp;

	tmp = data->smanager.sprites;
	while (tmp)
	{
		if (tmp->name[0] == name[0])
			return (tmp);
		tmp = tmp->next;
	}
	printf("image cannot found : %s\n", name);
	return (NULL);
}
