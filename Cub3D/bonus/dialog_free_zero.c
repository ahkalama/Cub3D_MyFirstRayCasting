/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_free_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:38:22 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/18 17:41:24 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	dialog_zero(t_data *data)
{
	t_sprites	*sprite;
	t_dialog	dialog;

	sprite = NULL;
	dialog = data->dialogs[data->controller.dindex];
	if (data->controller.strindex < ft_strlen(dialog.str))
		dialog_put(data, sprite, dialog);
	else
	{
		data->controller.wait = true;
		data->controller.strindex = 0;
		ft_bzero(data->controller.mainstr, ft_strlen(data->controller.mainstr));
		data->controller.dindex++;
	}
	if (data->controller.dindex >= data->controller.maxd)
		data->controller.playing = false;
	return (1);
}

void	dialog_free_system(t_data *data)
{
	t_sprites	*list;
	t_sprites	*tmp;
	int			i;

	i = 0;
	list = data->smanager.sprites;
	while (list)
	{
		tmp = list;
		list = list->next;
		mlx_destroy_image(data->mlx.ptr, tmp->image);
		free(tmp);
	}
	while (i < data->controller.maxd)
	{
		free(data->dialogs[i].character);
		free(data->dialogs[i].str);
		i++;
	}
}
