#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/01 23:34:05 by jbulant           #+#    #+#              #
#    Updated: 2018/01/03 02:33:26 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bmp2xpm_converter

SRCS =	srcs/main.c \
		srcs/ft_filechecker.c \
		srcs/ft_xpm_converter.c \
		srcs/ft_stack.c \
		srcs/ft_error.c \
		srcs/ft_file.c \
		srcs/get_next_line.c

OBJ = $(SRCS:%.c = %.o)

LIBFT = libft.a
LIBFTPATH = libft/
INCLUDEPATH = -Iincludes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDEPATH) $(OBJ) $(LIBFTPATH)$(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTPATH)

$(OBJ):
	echo $(SRCSFILES)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDEPATH) -c $(SRCSFILES)

