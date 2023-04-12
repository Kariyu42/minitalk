# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 13:42:41 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/12 14:13:17 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###
VIOLET		=\033[0;35m
GRAY		=\033[0;37m
OGREEN		=\033[0;32m
SKYBLUE		=\033[0;36m
BEIGE		=\033[38;5;223m
BOLD		=\033[1m
RESET		=\033[0m
ITALIC		=\033[3m

### Client & Server ###
NAME	=	client
SERV	=	server
PATH_S	=	srcs/

### Compiler ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[CLIENT] => $(RESET)""$(OGREEN) <$<> \033[K\r$(RESET)"

RM		=	rm -f

### Source files ###
SRCS_SERV	=	${addprefix ${}}
OBJ_SERV	=	$(SRCS_SERV:.c=.o)

### Rules ###
all:	$(SERV) $(NAME)

$(SERV):	$(OBJ_SERV)
