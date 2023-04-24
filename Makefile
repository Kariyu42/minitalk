# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 13:42:41 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/24 18:17:26 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###
GRAY		=\033[0;37m
OGREEN		=\033[0;32m
SKYBLUE		=\033[0;36m
BEIGE		=\033[38;5;223m
BOLD		=\033[1m
RESET		=\033[0m
ITALIC		=\033[3m

### Client & Server ###
NAME			=	server
CLIENT			=	client
PATH_SRCS		=	srcs/main/
LIBFT			=	libft/libft/
PRINT_PATH		=	libft/ft_printf/

### Bonus variables ###
BONUS_NAME		=	server_bonus
CLIENT_BONUS	=	client_bonus
BONUS_PATH		=	srcs/bonus/

### Compiler ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(PATH_SRCS)%.o: $(PATH_SRCS)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[MINITALK Files] => $(RESET)""$(OGREEN) <$<> \033[K\r$(RESET)"

$(BONUS_PATH)%.o: $(BONUS_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(OGREEN)$(BOLD)[MINITALK + BONUS] => $(RESET)""$(OGREEN) <$<> \033[K\r$(RESET)"

RM		=	rm -f

### Source files ###

SERVER_SRCS	=	${addprefix ${PATH_SRCS}, server.c}

CLIENT_SRCS	=	${addprefix ${PATH_SRCS}, client.c}

PRINT_SRCS	=	${addprefix ${PRINT_PATH}, ft_printf.c} \
				${addprefix ${PRINT_PATH}srcs/, add_numflags.c ft_get_precision.c \
				ft_get_width.c hexa_padd.c int_precision.c print_addr.c print_char.c \
				print_hexa.c print_int.c print_str.c print_unsigned.c}

OBJS_SERV	=	$(SERVER_SRCS:.c=.o) $(PRINT_SRCS:.c=.o)
OBJS_CLIENT	=	$(CLIENT_SRCS:.c=.o) $(PRINT_SRCS:.c=.o)

### BONUS ###

SERV_BONUS_SRCS		=	${addprefix ${BONUS_PATH}, server_bonus.c}

CLIENT_BONUS_SRCS	=	${addprefix ${BONUS_PATH}, client_bonus.c}

OBJS_BONUS_SERV		=	$(SERV_BONUS_SRCS:.c=.o) $(PRINT_SRCS:.c=.o)
OBJS_BONUS_CLIENT	=	$(CLIENT_BONUS_SRCS:.c=.o) $(PRINT_SRCS:.c=.o)

### Rules ###
all:	$(NAME)	$(CLIENT)

$(NAME):	$(OBJS_SERV)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)SERVER files compiled$(RESET) ✨\n\n"
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(OGREEN)$(BOLD)[LIBFT]$(RESET)\n"
	@make -C $(LIBFT)
	@printf "\n\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)SERVER COMPILED$(RESET) ✅\n\n"

$(CLIENT):	$(OBJS_CLIENT)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)CLIENT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)CLIENT COMPILED$(RESET) ✅\n"

bonus:	$(BONUS_NAME)	$(CLIENT_BONUS)

$(BONUS_NAME):	$(OBJS_BONUS_SERV)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)Server bonus files compiled$(RESET) ✨\n\n"
	@printf "$(SKYBLUE)$(BOLD)$(ITALIC)-> Compiling $(RESET)$(OGREEN)$(BOLD)[LIBFT]$(RESET)\n"
	@make -C $(LIBFT)
	@printf "\n\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)BONUS READY$(RESET) ✅\n\n"

$(CLIENT_BONUS):	$(OBJS_BONUS_CLIENT)
	@echo "\n"
	@printf "\t$(BEIGE)$(BOLD)$(ITALIC)Client bonus files compiled$(RESET) ✨\n\n"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)libft.a
	@printf "$(BOLD)$(ITALIC)$(LGREEN)CLIENT COMPILED$(RESET) ✅\n"

clean:
	@$(RM) $(OBJS_SERV)
	@printf "\n\t$(SKYBLUE)$(BOLD)$(ITALIC)Server files removed$(RESET) 🗂  ❌\n\n"
	@$(RM) $(OBJS_CLIENT)
	@printf "\n\t$(SKYBLUE)$(BOLD)$(ITALIC)Client files removed$(RESET) 🗂  ❌\n\n"
	@make clean -C $(LIBFT)
	@printf "\n\t$(BEIGE)$(BOLD)$(ITALIC)LIBFT files removed$(RESET) 📚 ❌\n\n"
	@$(RM) $(OBJS_BONUS_CLIENT)
	@$(RM) $(OBJS_BONUS_SERV)

fclean:	clean
	@$(RM) $(NAME)
	@printf "\n\t$(SKYBLUE)$(BOLD)$(ITALIC)[SERVER] binary removed$(RESET) 💽 ❌\n\n"
	@$(RM) $(CLIENT)
	@printf "\n\t$(SKYBLUE)$(BOLD)$(ITALIC)[CLIENT] binary removed$(RESET) 💽 ❌\n\n"
	@$(RM) $(LIBFT)libft.a
	@printf "\n\t$(BEIGE)$(BOLD)$(ITALIC)[LIBFT] removed$(RESET) 📚 ❌\n\n"
	@$(RM) $(BONUS_NAME)
	@$(RM) $(CLIENT_BONUS)

re:		fclean all

.PHONY:	all debug clean fclean bonus re bonus