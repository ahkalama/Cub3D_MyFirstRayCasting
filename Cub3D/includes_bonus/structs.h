/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:01:20 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 14:05:57 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_data	t_data;
typedef int				(*t_delegateMethod)(t_data*);

typedef struct s_dialog
{
	unsigned int	color;
	char			*str;
	char			*character;
}	t_dialog;

typedef struct s_dialog_c
{
	int				dindex;
	int				maxd;
	char			*mainstr;
	unsigned int	strindex;
	bool			wait;
	bool			playing;
}	t_dialog_c;

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

typedef struct s_mini_map
{
	double	x;
	double	y;
	double	radius;
}	t_mini_map;

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

typedef struct s_i_spr
{
	int		frames;
	t_img	*img;
}	t_i_spr;

typedef struct s_sprites
{
	char				*name;
	void				*image;
	int					x;
	int					y;
	struct s_sprites	*next;
}	t_sprites;

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

typedef struct s_sprite
{
	t_coordinates	screen;
	t_coordinates	collecs;
	t_coordinates	textures;
	t_dimen			sprite;
}	t_sprite;

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
	t_img			west;
	t_img			east;
	t_i_spr			door;
	t_i_spr			collec;
	t_list			*ll_door;
	t_list			*ll_collect;
	char			**map;
	int				ceiling_c;
	int				floor_c;
	double			depth[WIDTH];
	t_coordinates	sprite;
}	t_map;

typedef struct s_smanager
{
	t_sprites	*sprites;
}	t_smanager;

typedef struct s_data
{
	t_mlx				mlx;
	t_player			player;
	t_map				map;
	int					read_count;
	int					clear_ptr;
	t_dialog_c			controller;
	t_smanager			smanager;
	t_dialog			*dialogs;
	t_delegateMethod	dmethod;
}	t_data;

#endif
