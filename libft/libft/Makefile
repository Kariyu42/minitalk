# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 15:32:35 by kquetat-          #+#    #+#              #
#    Updated: 2023/04/13 17:02:37 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###
ITALIC		=\033[3m
BOLD		=\033[1m
LGREEN		=\033[1;32m
PALEBLUE	=\033[38;5;153m
BEIGE		=\033[38;5;223m
RESET		=\033[0m

### Name of library ###
NAME		=	libft.a
HEADER_PATH	=	../inc/
SRCS_PATH	=	srcs/
PATH_P		=	../ft_printf/srcs/
GNL_PATH	=	../get_next_line/

### Libft ###
SRC_LIB	=	${addprefix $(SRCS_PATH), ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memchr.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c}

### ft_printf & get_next_line ###
PRIN_SRC	=	${addprefix $(PATH_P), add_numflags.c, ft_get_precision.c, ft_get_width.c \
				hexa_padd.c int_precision.c print_addr.c print_char.c print_hexa.c print_int.c \
				print_str.c print_unsigned.c} \
				../ft_printf/ft_printf.c

GNL_SRC	=	${addprefix $(GNL_PATH), get_next_line.c, get_next_line_utils.c}

SRCS	=	SRC_LIB \
			PRIN_SRC \
			GNL_SRC \

### Compiler & Other variables ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(SRCS)%.o: $(SRCS)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(PALEBLUE)$(BOLD)$(ITALIC)[Libft]: $(RESET)""$(LGREEN)<$<> \033[K\r$(RESET)"

OBJ	=	$(SRCS:.c=.o)

RM	=	rm -f

### Rules ###
all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "\n"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(LGREEN)libft.a created !$(RESET)"

bonus:	$(OBJ) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(PRIN_OBJ) $(GNL_OBJ)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
	@$(RM) $(NAME) $(OBJ_BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus