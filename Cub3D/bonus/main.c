/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:29:08 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 13:57:26 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

static int	ft_arg_number_check(int argc)
{
	if (argc < 2)
	{
		printf("Error\nMissing map file.\nUSAGE: ./cub3d <file.cub>\n");
		return (0);
	}
	else if (argc > 2)
	{
		printf("Error\nInvalid arguments.\n./cub3d <file.cub>\n");
		return (0);
	}
	return (1);
}

static void	ft_init_mlx(t_data *data)
{
	data->mlx.win = NULL;
	data->mlx.img.img = NULL;
	data->mlx.ptr = mlx_init();
	data->dmethod = &get_dialog;
	data->smanager.sprites = NULL;
	add_image(data, "b", "textures/sedaarka.xpm");
	add_image(data, "c", "textures/ahmetarka.xpm");
	add_image(data, "d", "textures/ahmetarka1.xpm");
	init_dialogs(data);
	if (!data->mlx.ptr)
	{
		printf("Error. Couldn't initialize mlx.\n");
		exit(1);
	}
}

int	myfunc(t_data *data)
{
	data->dmethod(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		a;

	a = 0;
	if (ft_arg_number_check(argc) == 0)
		return (1);
	ft_init_mlx(&data);
	a = ft_import_map(&data, argv[1]);
	if (a != 1)
		ft_free_and_exit(&data, 1);
	a = ft_init_images(&data);
	if (a != 1)
		ft_free_and_exit(&data, 1);
	color_av(a);
	a = ft_start_game(&data);
	if (a != 1)
		ft_free_and_exit(&data, 1);
	return (0);
}
