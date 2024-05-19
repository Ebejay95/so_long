# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/05/08 16:31:46 by jeberle           #+#    #+#              #
#    Updated: 2024/05/18 15:33:44 by jonathanebe      ###   ########.fr        #
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

# Architecture-specific flags
ARCH := $(shell uname -m)
BREW_PREFIX := $(shell brew --prefix glfw)

ifeq ($(ARCH), arm64)
	CFLAGS += -target arm64-apple-macos11
	GLFW_LIB_PATH = /opt/homebrew/Cellar/glfw/3.4/lib
	GLFW_INCLUDE_PATH = /opt/homebrew/Cellar/glfw/3.4/include
else
	CFLAGS += -target x86_64-apple-macos10.15
	GLFW_LIB_PATH = /usr/local/opt/glfw/lib
	GLFW_INCLUDE_PATH = /usr/local/opt/glfw/include
endif

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
MLXFTFLAGS=-L$(MLXFT_BUILD_DIR) -lmlx42 -L$(GLFW_LIB_PATH) -I$(GLFW_INCLUDE_PATH) -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

#------------------------------------------------------------------------------#
#--------------                        SRC                        -------------#
#------------------------------------------------------------------------------#

SRCS= \
so_long.c

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
	@git submodule update --init --recursive --remote > /dev/null 2>&1
	@mkdir -p $(MLXFT_BUILD_DIR)
	@cd $(MLXFT_DIR) && cmake $(MLXFT_BUILD_FLAGS) ../$(MLXFT_BUILD_DIR) && cd .. && cd $(MLXFT_BUILD_DIR) && $(MAKE)
	@echo "$(GREEN)MLX42 built successfully$(X)"

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $^ $(LIBFTFLAGS) $(MLXFTFLAGS)
	@echo "$(SUCCESS)"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)objects deleted$(X)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)so_long deleted$(X)"

re: fclean all
