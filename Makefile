# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 19:27:00 by edelarbr          #+#    #+#              #
#    Updated: 2023/07/21 22:18:08 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
NAME_BONUS	:=	multipipex

# ------------------------------ Sources -----------------------------

SRCS :=			srcs/utils/find_cmd_path.c \
				srcs/utils/ft_strlen.c \
				srcs/utils/struct_init.c \
				srcs/utils/ft_strjoin.c \
				srcs/utils/ft_isascii.c \
				srcs/utils/ft_split.c \
				srcs/utils/ft_strncmp.c \
				srcs/utils/ft_putstr.c \
				srcs/utils/ft_split_w_slash.c \
				srcs/utils/free_print_exit.c \
				srcs/utils/get_path.c \
				srcs/parser/parser.c \
				srcs/pipex.c \

SRCS_BONUS :=	bonus/utils/find_cmd_path.c \
				bonus/utils/ft_strlen.c \
				bonus/utils/ft_strjoin.c \
				bonus/utils/ft_isascii.c \
				bonus/utils/ft_split.c \
				bonus/utils/ft_strncmp.c \
				bonus/utils/ft_putstr.c \
				bonus/utils/ft_split_w_slash.c \
				bonus/utils/free_print_exit.c \
				bonus/utils/get_path.c \
				bonus/utils/struct_init_bonus.c \
				bonus/parser/parser_bonus.c \
				bonus/pipex_bonus.c \

OBJS		:=	$(SRCS:.c=.o)
OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $(<:.c=.o)

# ------------------------------ Flags -------------------------------

CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror

# ------------------------------ Colors ------------------------------

# Colors

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ so_long --------------------------------


all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
				@ echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

$(NAME_BONUS):	$(OBJS_BONUS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME_BONUS) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)
				@ echo "$(GREEN)$(NAME_BONUS) created $(CLR_RMV)✔️"


# --  ---------------------------- Rules -----------------------------------

clean:
				@ $(RM) $(OBJS) $(OBJS_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)and $(CYAN)$(NAME_BONUS) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM) $(NAME_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)and $(CYAN)$(NAME_BONUS) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all clean fclean re