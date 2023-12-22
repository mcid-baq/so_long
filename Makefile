# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:04:04 by mcid-baq          #+#    #+#              #
#    Updated: 2023/12/21 17:35:13 by mcid-baq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc -Wall -Wextra -Werror
PRINTF = printf/libftprintf.a
MLX42 = MLX42/build/libmlx42.a
GET_NEXT_LINE = get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
HEADER = so_long.h

LIBS = -Iinclude -lglfw -L"/Users/mcid-baq/.brew/opt/glfw/lib/"
SRC = so_long.c\
	utils/checking_chr.c\
	utils/fill.c\
	utils/free_error.c\
	utils/free_map.c\
	utils/key_mv.c\
	utils/map_painting.c\
	utils/print_error.c\
	utils/read_map.c\

OBJS = $(SRC:.c=.o)

all : mlx42 $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(MLX42) $(GET_NEXT_LINE) $(HEADER)
	$(CC) $(OBJS) $(PRINTF) $(GET_NEXT_LINE) $(MLX42) $(LIBS) -o $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(PRINTF):
	@make -C printf

$(MLX42):
	@make -C MLX42/build

clean:
	@rm -rf $(OBJS)
	@make -C MLX42/build clean
	@make -C printf fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
