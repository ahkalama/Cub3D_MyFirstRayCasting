/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:00:19 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/26 14:04:46 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "./defines/keys.h"
# include "./defines/map.h"
# include "./defines/mini_map.h"

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_EXIT 17
# define ON_MOUSEMOVE 6
# define NO_MASK 0

# define FOV 90
# define ROT_SPEED 0.1
# define COLLECT_FRAME 0.3
# define DOOR_FRAME 1
# define OFF_SET 0.5
# define SPEED 0.15

# define WIDTH 1280
# define HEIGHT 720
# define STRNWDT 300
# define STRNHDT 600

# define F_C_COLOR_DEF -255

#endif
