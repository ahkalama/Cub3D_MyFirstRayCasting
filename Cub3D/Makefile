# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 12:53:46 by ahkalama          #+#    #+#              #
#    Updated: 2024/02/26 16:55:10 by ahkalama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
B_NAME := cub3D_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g -ggdb

RM := rm -f

END	    = \033[0m
BOLD    = \033[1m
ITALIC  = \033[3m

BLACK   = \033[30m
RED     = \033[31m
BLUE    = \033[34m
CYAN    = \033[36m

SRCS_DIR := srcs/

SRCS := ./srcs/calculate.c \
		./srcs/checks.c \
		./srcs/ft_assign_texture.c \
		./srcs/ft_draw_wall.c \
		./srcs/ft_exit_and_free.c \
		./srcs/ft_fill_textures.c \
		./srcs/ft_import_map.c \
		./srcs/ft_init_images.c \
		./srcs/ft_move_player.c \
		./srcs/ft_parse_map_closed.c \
		./srcs/ft_parse_map.c \
		./srcs/ft_render.c \
		./srcs/ft_start_game.c \
		./srcs/ft_update.c \
		./srcs/ft_wall_dimension.c \
		./srcs/gnl_utils.c \
		./srcs/gnl.c \
		./srcs/list_utils.c \
		./srcs/main.c \
		./srcs/color_av.c \
		./srcs/ft_garbage_utils.c \
		./srcs/ft_car_driving.c \

OBJS_DIR := objs/

OBJS := ./objs/calculate.o \
		./objs/checks.o \
		./objs/ft_assign_texture.o \
		./objs/ft_draw_wall.o \
		./objs/ft_exit_and_free.o \
		./objs/ft_fill_textures.o \
		./objs/ft_import_map.o \
		./objs/ft_init_images.o \
		./objs/ft_move_player.o \
		./objs/ft_parse_map_closed.o \
		./objs/ft_parse_map.o \
		./objs/ft_render.o \
		./objs/ft_start_game.o \
		./objs/ft_update.o \
		./objs/ft_wall_dimension.o \
		./objs/gnl_utils.o \
		./objs/gnl.o \
		./objs/list_utils.o \
		./objs/main.o \
		./objs/color_av.o \
		./objs/ft_garbage_utils.o \
		./objs/ft_car_driving.o \

BONUS_DIR := bonus/

BONUS_SRCS := ./bonus/calculate.c \
		./bonus/checks.c \
		./bonus/doors_utils.c \
		./bonus/ft_assign_texture.c \
		./bonus/ft_draw_wall.c \
		./bonus/ft_exit_and_free.c \
		./bonus/ft_fill_textures.c \
		./bonus/ft_import_map.c \
		./bonus/ft_init_images.c \
		./bonus/ft_mini_map_draw_comps.c \
		./bonus/ft_mini_map.c \
		./bonus/ft_move_player.c \
		./bonus/ft_parse_map_closed.c \
		./bonus/ft_parse_map.c \
		./bonus/ft_render.c \
		./bonus/ft_sprites.c \
		./bonus/ft_start_game.c \
		./bonus/ft_update.c \
		./bonus/ft_wall_dimension.c \
		./bonus/gnl_utils.c \
		./bonus/gnl.c \
		./bonus/list_utils.c \
		./bonus/list_utilsv2.c \
		./bonus/main.c \
		./bonus/color_av.c \
		./bonus/ft_garbage_utils.c \
		./bonus/ft_car_driving.c \
		./bonus/spritemanager.c \
		./bonus/dialogsystem.c \
		./bonus/dialogsystemutils.c \
		./bonus/linkedlist.c \
		./bonus/dialog_free_zero.c \

BONUS_OBJS_DIR := bonus_obj/

BONUS_OBJS := ./bonus_obj/calculate.o \
		./bonus_obj/checks.o \
		./bonus_obj/doors_utils.o \
		./bonus_obj/ft_assign_texture.o \
		./bonus_obj/ft_draw_wall.o \
		./bonus_obj/ft_exit_and_free.o \
		./bonus_obj/ft_fill_textures.o \
		./bonus_obj/ft_import_map.o \
		./bonus_obj/ft_init_images.o \
		./bonus_obj/ft_mini_map_draw_comps.o \
		./bonus_obj/ft_mini_map.o \
		./bonus_obj/ft_move_player.o \
		./bonus_obj/ft_parse_map_closed.o \
		./bonus_obj/ft_parse_map.o \
		./bonus_obj/ft_render.o \
		./bonus_obj/ft_sprites.o \
		./bonus_obj/ft_start_game.o \
		./bonus_obj/ft_update.o \
		./bonus_obj/ft_wall_dimension.o \
		./bonus_obj/gnl_utils.o \
		./bonus_obj/gnl.o \
		./bonus_obj/list_utils.o \
		./bonus_obj/list_utilsv2.o \
		./bonus_obj/main.o \
		./bonus_obj/color_av.o \
		./bonus_obj/ft_garbage_utils.o \
		./bonus_obj/ft_car_driving.o \
		./bonus_obj/spritemanager.o \
		./bonus_obj/dialogsystem.o \
		./bonus_obj/dialogsystemutils.o \
		./bonus_obj/linkedlist.o \
		./bonus_obj/dialog_free_zero.o \

LIBFT_DIR := libft

MINILIBX_DIR := minilibx

all: $(NAME)
bonus : $(B_NAME)

$(NAME): $(OBJS_DIR) $(OBJS) coffee
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -framework OpenGL  -framework AppKit -L./minilibx -lmlx -g $(OBJS) -o $(NAME) 
	@rm -rf $(B_NAME) 
	@echo "$(BOLD)$(BLUE)			------------------------------------------------------ 		Compiled Cub3D 		--------------------------------------------------------------------"
	
$(B_NAME): $(BONUS_OBJS_DIR) $(BONUS_OBJS) coffee
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -framework OpenGL  -framework AppKit -L./minilibx -lmlx -g $(BONUS_OBJS) -o $(B_NAME)
	@rm -rf $(NAME)
	@echo "$(BOLD)$(BLUE)			------------------------------------------------------ 		Compiled $(RED)Bonus$(END)		$(BOLD)$(BLUE)--------------------------------------------------------------------"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BONUS_OBJS_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(BONUS_OBJS_DIR):
	@mkdir -p $(BONUS_OBJS_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(BONUS_OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@echo "$(BOLD)$(ITALIC)											Running FCLEAN\n"
	

re: fclean all

coffee:

	@echo "\n\n	██╗    ██╗ █████╗ ██████╗ ███╗   ██╗██╗███╗   ██╗██████╗  $(RED)██╗$(END)    ██████╗ ███████╗ █████╗ ██████╗     ██████╗ ███████╗███████╗ ██████╗ ██████╗ ███████╗    ██████╗ ██╗      █████╗ ██╗   ██╗   "
	@echo "	██║    ██║██╔══██╗██╔══██╗████╗  ██║██║████╗  ██║██╔════╝ $(RED)██║$(END)    ██╔══██╗██╔════╝██╔══██╗██╔══██╗    ██╔══██╗██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝$(RED)██╗$(END)"
	@echo "	██║ █╗ ██║███████║██████╔╝██╔██╗ ██║██║██╔██╗ ██║██║  ███╗$(RED)██║$(END)    ██████╔╝█████╗  ███████║██║  ██║    ██████╔╝█████╗  █████╗  ██║   ██║██████╔╝█████╗      ██████╔╝██║     ███████║ ╚████╔╝ $(RED)╚═╝$(END)"
	@echo "	██║███╗██║██╔══██║██╔══██╗██║╚██╗██║██║██║╚██╗██║██║   ██║$(RED)╚═╝$(END)    ██╔══██╗██╔══╝  ██╔══██║██║  ██║    ██╔══██╗██╔══╝  ██╔══╝  ██║   ██║██╔══██╗██╔══╝      ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  $(RED)██╗$(END)"
	@echo "	╚███╔███╔╝██║  ██║██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝$(RED)██╗$(END)    ██║  ██║███████╗██║  ██║██████╔╝    ██████╔╝███████╗██║     ╚██████╔╝██║  ██║███████╗    ██║     ███████╗██║  ██║   ██║   $(RED)╚═╝$(END)"
	@echo "	 ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ $(RED)╚═╝$(END)    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝     ╚═════╝ ╚══════╝╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝      $(END)"



	@	@echo "\n$(BLACK)		A very small percentage of people may have seizures when exposed to certain visual images, including $(BOLD)$(CYAN)flashing lights$(END)$(BLACK) or patterns that may appear in video games.$(END)"
	@	@echo "	    $(BLACK) Even if they've never had one before. It can happen to anyone, even if they don't know they have a condition that causes $(BOLD)$(CYAN)epileptic seizures$(END)$(BLACK) when playing video games.$(END)\n\n\n"
	@echo "\n								$(ITALIC)' This game was made with great care by $(END)$(BLACK)ahkalama$(END) $(ITALIC)and$(END) $(BLACK)sekilinc$(END)$(ITALIC) ,\n"
	@echo "\n   			    						        $(ITALIC)Thanks for supports $(END)$(BLACK)canodis(rtosun)$(END)\n"

.PHONY: all clean fclean re bonus
