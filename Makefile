# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:01:08 by rrhaenys          #+#    #+#              #
#    Updated: 2019/02/20 17:23:15 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = sdl

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

### PATH ###
SRCS_PATH = src/
LIBUI_PATH = libui/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = #-Wall -Werror -Wextra

INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/ -I$(LIBUI_PATH)includes/

SRCS_NAME = $(shell find $(SRCS_PATH) | grep -E ".+\.c" | cut -c5-)

FOLDERS_SRCS = $(addprefix $(OBJ_PATH), $(shell find src/ -type d | cut -c5-))

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	INC += -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_image -lm
endif
ifeq ($(UNAME_S),Darwin)
	SDL =  -F ./includes/frameworks/ -framework SDL2 \
									-framework SDL2_image \
									-framework SDL2_ttf \
									-framework SDL2_mixer
	INC += -I includes -I libft -I kiss_sdl -I includes/frameworks/SDL2.framework/Headers \
			-I includes/frameworks/SDL2_image.framework/Versions/A/Headers \
			-I includes/frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-I includes/frameworks/SDL2_mixer.framework/Versions/A/Headers
	FRAMEWORKS = -F includes/frameworks/
endif

all: libs $(NAME)

libs:
	@make -w -C $(LIBFT_PATH)
	@echo "\033[92m$(LIBFT_PATH)\033[0m compiled."
	@make -w -C $(LIBUI_PATH)
	@echo "\033[92m$(LIBUI_PATH)\033[0m compiled."

$(NAME): $(OBJ) libui/libui.a libft/libft.a
	@gcc -g $(FLAGS) $(OBJ) libui/libui.a $(SDL) $(INCLUDES) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME) $(FRAMEWORKS)
	@echo "\033[35m$(NAME)\033[0m created."

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c includes/ft_guimp.h libui/includes/ft_sdl.h libui/includes/ft_struct.h
	@mkdir -p $(FOLDERS_SRCS)
	@gcc -c -g $(FLAGS) $(INC) $(INCLUDES) $< -o $@ $(FRAMEWORKS)
	@echo "\033[33m$<\033[0m compiled."

clean:
	@make -w -C $(LIBFT_PATH)/ clean
	@make -w -C $(LIBUI_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	
fclean: clean
	@make -w -C $(LIBFT_PATH)/ fclean
	@make -w -C $(LIBUI_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	
re: fclean all

delete:
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(OBJ_PATH)

install_ubuntu:
	sudo apt-get install gcc -y
	sudo apt-get install libsdl2-ttf-dev -y
	sudo apt-get install libsdl2-dev -y
	sudo apt-get install libsdl2-2.0 -y
	sudo apt-get install libsdl2-image-dev -y

install_mac:
	brew install sdl_ttf
	brew install sdl2_image
	brew install sdl2

pull: fclean
	git pull

rl: delete all

.PHONY: all, clean, fclean, re, rl, delete, install_ubuntu, pull
