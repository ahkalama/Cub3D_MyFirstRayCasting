/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:30:47 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 14:05:17 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_dimen
{
	double	width;
	double	height;
}	t_dimen;

typedef struct s_coordinates
{
	double	x;
	double	y;
}	t_coordinates;

typedef struct s_object
{
	double	x;
	double	y;
	double	frame;
}	t_object;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		steps;
	int		*get_addr;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_render
{
	double			degree;
	double			angle;
	t_coordinates	wall_hit;
	t_dimen			wall_dimen;
	double			distance;
	int				direction;
	double			wall_height;
	int				y_tex;
}	t_render;

typedef struct s_player
{
	t_coordinates			pos;
	t_coordinates			dir;
	t_coordinates			move;
	double					angle;
	double					rotate;
}	t_player;

typedef struct s_map
{
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
	char			**map;
	int				ceiling_c;
	int				floor_c;
}	t_map;

typedef struct s_data
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
}	t_data;

#endif
