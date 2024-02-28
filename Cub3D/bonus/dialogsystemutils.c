/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialogsystemutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:48:33 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 12:02:53 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

char	*ft_dup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*get_one_str(char *str, int i, int len)
{
	char	*res;

	while (str[i++] != 32)
		len++;
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*strjoin_char(char *str, char ch)
{
	char	*result;

	result = (char *)malloc(ft_strlen(str) + 2);
	if (result != NULL)
	{
		if (str)
			ft_strcpy(result, str);
		result[ft_strlen(str)] = ch;
		result[ft_strlen(str) + 1] = '\0';
	}
	else if (result == NULL)
		return (NULL);
	if (str)
		free(str);
	return (result);
}

void	parse_that_dialog(t_dialog *dialog, char *readed, int x, int y)
{
	int	i;

	i = 0;
	x = 0;
	y = 0;
	dialog->color = ft_atoi(&readed[i]);
	go_next_data(readed, &i);
	dialog->character = get_one_str(&readed[i], x, y);
	go_next_data(readed, &i);
	dialog->str = ft_dup(&readed[i]);
	if (readed)
		free(readed);
}

void	init_dialogs(t_data *data)
{
	char	*readed;

	readed = NULL;
	data->controller.dindex = 0;
	data->controller.playing = true;
	data->controller.wait = false;
	data->controller.strindex = 0;
	data->controller.mainstr = NULL;
	read_dialogs(data, readed);
}
