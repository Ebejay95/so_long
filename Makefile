# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 16:31:46 by jeberle           #+#    #+#              #
#    Updated: 2024/06/07 19:46:48 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#--------------                       PRINT                       -------------#
#------------------------------------------------------------------------------#

BLACK := \033[30m
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
MAGENTA := \033[35m
CYAN := \033[36m
X := \033[0m

SUCCESS := \n$(GREEN)\
██████████████████████████████████████████████████████$(X)\n\
$(X)\n\
███████  ███████    █        ███████  ██    █  ███████$(X)\n\
█        █     █    █        █     █  █ █   █  █      $(X)\n\
███████  █     █    █        █     █  █  █  █  █   ███$(X)\n\
$(BLACK)______$(X)█  █     █    █        █     █  █   █ █  █     █$(X)\n\
███████  ███████    ███████  ███████  █    ██  ███████$(X)\n\
$(X)\n\
$(GREEN)██████████████████████████████████████████████████████$(X)\n\

#------------------------------------------------------------------------------#
#--------------                      GENERAL                      -------------#
#------------------------------------------------------------------------------#

NAME=so_long

#------------------------------------------------------------------------------#
#--------------                       FLAGS                       -------------#
#------------------------------------------------------------------------------#

CC=cc
CFLAGS=-Wall -Wextra -Werror


ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g
endif

DEPFLAGS=-MMD -MP

#------------------------------------------------------------------------------#
#--------------                        DIR                        -------------#
#------------------------------------------------------------------------------#

OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := .
SRC_DIRS := .

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

#------------------------------------------------------------------------------#
#--------------                        LIBS                       -------------#
#------------------------------------------------------------------------------#

LIBFT_DIR=libft
LIBFT=libft.a
LIBFT_LIB=$(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS=-L$(LIBFT_DIR) -lft

MLXFT_DIR=./mlx42
MLXFT=libmlx42.a
MLXFT_BUILD_FLAGS=-B
MLXFT_BUILD_DIR=./mlx_build
MLXFT_LIB=$(MLXFT_BUILD_DIR)/$(MLXFT)
MLXFTFLAGS=-L$(MLXFT_BUILD_DIR) -lmlx42 -lglfw

#------------------------------------------------------------------------------#
#--------------                        SRC                        -------------#
#------------------------------------------------------------------------------#

SRCS= \
mandatory/so_long.c \
mandatory/initialize.c \
mandatory/initialize2.c \
mandatory/actions.c \
mandatory/map.c \
mandatory/player.c \
mandatory/termination.c \
mandatory/texture_items.c \
mandatory/texture_map.c \
mandatory/texture_player_up.c \
mandatory/texture_player_down.c \
mandatory/texture_player_left.c \
mandatory/texture_player_right.c \
mandatory/texture_player.c \
mandatory/texture_helper.c \
mandatory/texture.c \
mandatory/validation.c \
mandatory/validation_input.c \
mandatory/validation_content.c

BONUS_SRCS= \
bonus/so_long_bonus.c \
bonus/animation_bonus.c \
bonus/initialize_bonus.c \
bonus/initialize2_bonus.c \
bonus/actions_bonus.c \
bonus/map_bonus.c \
bonus/player_bonus.c \
bonus/monsters_bonus.c \
bonus/monsters_helper_bonus.c \
bonus/sound_bonus.c \
bonus/sound2_bonus.c \
bonus/sound3_bonus.c \
bonus/termination_bonus.c \
bonus/texture_items_bonus.c \
bonus/texture_map_bonus.c \
bonus/texture_monster_bonus.c \
bonus/texture_player_up_bonus.c \
bonus/texture_player_down_bonus.c \
bonus/texture_player_left_bonus.c \
bonus/texture_player_right_bonus.c \
bonus/texture_player_bonus.c \
bonus/texture_helper_bonus.c \
bonus/texture_bonus.c \
bonus/validation_bonus.c \
bonus/validation_input_bonus.c \
bonus/validation_content_bonus.c

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
BONUS_OBJECTS := $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:%.c=%.o))

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re libft

all: $(MLXFT_LIB) $(LIBFT_LIB) $(NAME)

bonus: $(MLXFT_LIB) $(LIBFT_LIB) $(BONUS_OBJECTS)
	@$(MAKE) $(NAME) "OBJECTS=$(BONUS_OBJECTS)"

-include $(OBJECTS:.o=.d)
-include $(BONUS_OBJECTS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR)

$(MLXFT_LIB):
	@rm -rf mlx42
	@git clone https://github.com/codam-coding-college/MLX42.git mlx42
	@mkdir -p $(MLXFT_BUILD_DIR)
	@cd $(MLXFT_DIR) && cmake $(MLXFT_BUILD_FLAGS) ../$(MLXFT_BUILD_DIR) && cd .. && cd $(MLXFT_BUILD_DIR) && $(MAKE)
	@echo "$(GREEN)MLX42 built successfully$(X)"

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $^ $(LIBFTFLAGS) $(MLXFTFLAGS)
	@echo "$(SUCCESS)"

clean:
	@rm -rf mlx42
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)objects deleted$(X)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)so_long deleted$(X)"

re: fclean all
