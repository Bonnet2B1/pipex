# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 19:27:00 by edelarbr          #+#    #+#              #
#    Updated: 2023/07/10 20:05:30 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	*/*.c \

OBJS :=	$(SRCS:.c=.o)

.c.o:
	@ $(GCC) -c $< -o $(<:.c=.o)

# ------------------------------ Flags -------------------------------

GCC = @gcc -Wall -Werror -Wextra -g3 -fsanitize=address

# ------------------------------ Colors ------------------------------

# Colors

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ so_long --------------------------------

RM			:=	rm -f

all: $(NAME)

$(NAME):
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(GCC) $(SRCS) -o $(NAME)
				@ echo "$(GREEN)$(NAME) created[0m ✔️"

# --  ---------------------------- Rules -----------------------------------

clean:
				@ $(RM) $(OBJS) $(OBJS_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM) $(NAME_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all fclean re