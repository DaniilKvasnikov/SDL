# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 14:25:41 by rrhaenys          #+#    #+#              #
#    Updated: 2019/08/18 20:22:32 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
MAKEFLAGS += -s
endif

NAME = libui.a
FLAGS = #-Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
SRCS_NAME = $(shell ls src | grep -E ".+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRCS_NAME))
INCLUDE = -Iincludes -I ../libft/includes/
COMMAND = gcc
OBJ = $(addprefix $(OBJ_DIR), $(SRCS_NAME:.c=.o))


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	INCLUDE += -lSDL2 -lSDL2_ttf
endif
ifeq ($(UNAME_S),Darwin)
	SDL =  -F ./includes/frameworks/ -framework SDL2 \
									-framework SDL2_image \
									-framework SDL2_ttf \
									-framework SDL2_mixer
	INCLUDE += -I includes -I libft -I kiss_sdl -I includes/frameworks/SDL2.framework/Headers \
			-I includes/frameworks/SDL2_image.framework/Versions/A/Headers \
			-I includes/frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-I includes/frameworks/SDL2_mixer.framework/Versions/A/Headers
	FRAMEWORKS = -F includes/frameworks/
endif

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $< $(FRAMEWORKS)

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
