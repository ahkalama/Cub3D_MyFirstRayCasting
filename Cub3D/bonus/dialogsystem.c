/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialogsystem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:04:52 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 15:55:52 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"
#include "../includes_bonus/defines.h"

void	go_next_data(char *readed, int *i)
{
	while (readed[*i] != 32)
		(*i)++;
	while (readed[*i] == 32)
		(*i)++;
}

bool	read_dialogs(t_data *data, char *readed)
{
	int	fd;
	int	i;

	fd = open("dialog/dialogs.txt", O_RDONLY);
	if (fd == -1)
		return (false);
	readed = get_next_line(fd);
	if (readed == NULL)
		return (false);
	data->dialogs = malloc(sizeof(t_dialog) * ft_atoi(readed));
	if (!data->dialogs)
		return (false);
	i = 0;
	free(readed);
	while (true)
	{
		readed = get_next_line(fd);
		if (readed == NULL)
			break ;
		parse_that_dialog(&data->dialogs[i], readed, -1, -1);
		i++;
	}
	data->controller.maxd = i;
	return (true);
}

static void	join(t_dialog_c *controller, t_dialog *dialog)
{
	controller->mainstr = strjoin_char(controller->mainstr,
			dialog->str[controller->strindex++]);
}

void	dialog_put(t_data *data, t_sprites *sprite, t_dialog dialog)
{
	mlx_clear_window(data->mlx.ptr, data->mlx.win);
	sprite = get_image(data, dialog.character);
	if (sprite != NULL)
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			sprite->image, sprite->x, sprite->y);
	}
	join(&data->controller, &dialog);
	mlx_string_put(data->mlx.ptr, data->mlx.win, STRNWDT, STRNHDT,
		dialog.color, data->controller.mainstr);
}

int	get_dialog(t_data *data)
{
	t_sprites	*sprite;

	sprite = NULL;
	if (!data->controller.playing || data->controller.wait)
	{
		if (data->controller.wait == false)
		{
			data->controller.wait = true;
			mlx_clear_window(data->mlx.ptr, data->mlx.win);
			data->dmethod = &ft_update;
			dialog_free_system(data);
			free(data->dialogs);
		}
		return (0);
	}
	return (dialog_zero(data));
}
