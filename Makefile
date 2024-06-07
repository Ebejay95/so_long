# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 16:31:46 by jeberle           #+#    #+#              #
#    Updated: 2024/06/07 16:28:25 by jeberle          ###   ########.fr        #
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
so_long.c \
animation.c \
initialize.c \
initialize2.c \
actions.c \
map.c \
player.c \
monsters.c \
monsters_helper.c \
sound.c \
sound2.c \
sound3.c \
termination.c \
texture_items.c \
texture_map.c \
texture_monster.c \
texture_player_up.c \
texture_player_down.c \
texture_player_left.c \
texture_player_right.c \
texture_player.c \
texture_helper.c \
texture.c \
validation.c \
validation_input.c \
validation_content.c

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re libft

all: $(MLXFT_LIB) $(LIBFT_LIB) $(NAME)

-include $(OBJECTS:.o=.d)

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
