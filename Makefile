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
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = #-Wall -Werror -Wextra

INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = $(shell find src/  | grep -E ".+\.c" | cut -c5-)

FOLDERS_SRCS = $(addprefix $(OBJ_PATH), $(shell find src/ -type d | cut -c5-))

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	INC = -lSDL2 -lSDL2_ttf -I ./includes/ -I ./$(LIBFT_PATH)includes/
endif
ifeq ($(UNAME_S),Darwin)
	SDL =  -F ./includes/frameworks/ -framework SDL2 \
									-framework SDL2_image \
									-framework SDL2_ttf \
									-framework SDL2_mixer
	INCLUDES =	-I includes -I libft -I kiss_sdl \
				-I includes/frameworks/SDL2.framework/Headers \
				-I includes/frameworks/SDL2_image.framework/Versions/A/Headers \
				-I includes/frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I includes/frameworks/SDL2_mixer.framework/Versions/A/Headers
	FRAMEWORKS = -F includes/frameworks/
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[92m$(LIBFT_PATH)\033[0m compiled."
	@gcc -g $(FLAGS) $(OBJ) $(SDL) $(INCLUDES) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME) $(FRAMEWORKS)
	@echo "\033[35m$(NAME)\033[0m created."

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(FOLDERS_SRCS)
	@gcc -c -g $(FLAGS) $(INC) $< -o $@ $(FRAMEWORKS)
	@echo "\033[33m$<\033[0m compiled."
	
clean:
	@make -w -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	
fclean: clean
	@make -w -C $(LIBFT_PATH)/ fclean
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

pull: fclean
	git pull

rl: delete all

.PHONY: all, clean, fclean, re, rl, delete, install_ubuntu, pull
