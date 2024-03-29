/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:32 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/27 15:02:16 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

static int	ft_key_press(int k_code, t_data *data)
{
	if (k_code == W)
		data->player.move.y = -1;
	else if (k_code == S)
		data->player.move.y = 1;
	else if (k_code == A)
	{
		ft_car_left(data);
		data->player.move.x = -1;
	}
	else if (k_code == D)
	{
		ft_car_right(data);
		data->player.move.x = 1;
	}
	else if (k_code == LEFT)
		data->player.rotate = -1;
	else if (k_code == RIGHT)
		data->player.rotate = 1;
	else if (k_code == ESC)
		ft_free_and_exit(data, 0);
	else if (k_code == F)
		ft_open_close_door(data);
	else if (k_code == ENTER)
		data->controller.wait = false;
	return (0);
}

static int	ft_key_release(int k_code, t_data *data)
{
	if (k_code == W || k_code == S)
		data->player.move.y = 0;
	else if (k_code == A || k_code == D)
		data->player.move.x = 0;
	else if (k_code == RIGHT || k_code == LEFT)
		data->player.rotate = 0;
	return (0);
}

static int	ft_mouse_rotation(int x, int y, t_data *data)
{
	double	difference;

	(void)y;
	difference = x - (WIDTH / 2);
	data->player.angle = ft_update_radian(data->player.angle,
			(difference / 1000.0));
	mlx_mouse_move(data->mlx.win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	ft_start_game(t_data *data)
{
	data->mlx.win = (void *)mlx_new_window(data->mlx.ptr,
			WIDTH, HEIGHT, "TofAsk 3D");
	if (!data->mlx.win)
	{
		printf("Error\nCouldn't open window.\n");
		return (-1);
	}
	data->player.move.x = 0;
	data->player.move.y = 0;
	data->player.rotate = 0;
	mlx_mouse_hide();
	mlx_hook(data->mlx.win, ON_KEYDOWN, NO_MASK, ft_key_press, data);
	mlx_hook(data->mlx.win, ON_KEYUP, NO_MASK, ft_key_release, data);
	mlx_hook(data->mlx.win, ON_MOUSEMOVE, NO_MASK, ft_mouse_rotation, data); // Mouse Controller
	mlx_hook(data->mlx.win, ON_EXIT, NO_MASK, ft_free_and_exit, data);
	mlx_loop_hook(data->mlx.ptr, myfunc, data);
	mlx_loop(data->mlx.ptr);
	return (1);
}
