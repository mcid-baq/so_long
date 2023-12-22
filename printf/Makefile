# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 12:22:29 by mcid-baq          #+#    #+#              #
#    Updated: 2023/05/18 11:53:01 by mcid-baq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

LIB_INC = -L$(LIBFT_DIR) -lft
LFLAGS = $(LIBFT_DIR)/libft.a

NAME = libftprintf.a

FILES = ft_printf.c ft_printchar.c ft_printhex.c ft_printnbr.c ft_printstr.c ft_printunsignbr.c

OBJECTS = $(FILES:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_DIR)/libft.a
	cp $(LFLAGS) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT_DIR)/libft.a:
	$(LIBFT_MAKE)

$(OBJECTS): $(FILES) $(HEADER)
	$(CC) $(FLAGS) $(LIBFT_INC) -c $(FILES)

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJECTS)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean