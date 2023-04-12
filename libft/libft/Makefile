# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:32:35 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/12 10:18:14 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###
ITALIC		=\033[3m
BOLD		=\033[1m
LGREEN		=\033[1;32m
PALEBLUE	=\033[38;5;153m
RESET		=\033[0m

### Name of library ###
NAME 		=	libft.a
HEADER_PATH	=	../inc/
SRCS_PATH	=	srcs/

### Compiler & Other variables ###
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(PALEBLUE)$(BOLD)$(ITALIC)Loading: $(RESET)""$(LGREEN)<$<> \033[K\r$(RESET)"

OBJ			=	$(SRCS:.c=.o)
OBJ_BONUS	=	$(SRCS_BONUS:.c=.o)

RM	=	rm -f

### Mandatory part ###
SRCS	=	${addprefix $(SRCS_PATH), ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
			ft_memchr.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c}

### Bonus part ###
SRCS_BONUS =	${addprefix $(SRCS_PATH), ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c}

### Rules ###
all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "\n"
	@echo -e "$(YELLOW)Creating libft.a...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo -e "$(GREEN)libft.a created !$(RESET)"

bonus:	$(OBJ) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
	@$(RM) $(NAME) $(OBJ_BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus