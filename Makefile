# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:52:51 by fmarggra          #+#    #+#              #
#    Updated: 2023/11/20 11:53:31 by fmarggra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME2	=	checker
INC		= 	push_swap.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
AR		=	ar rc
RM		=	rm -f
# LIBFT	= 	cd /nfs/homes/fmarggra/Core/libft
# LDFLAGS	= 	-L$(LIBFT) -lft

SRC		=	setup_structure.c sort_direction.c libft.c\
 			operations.c sort.c sort_small_helper.c\
 			main.c sort_cost.c sort_target.c

SRC2	=	checker.c get_next_line_utils.c get_next_line.c\
			setup_structure.c sort_target.c operations.c\
			sort_small_helper.c libft.c

OBJS	=	$(SRC:.c=.o)
OBJS2	=	$(SRC2:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)
			# $(CC) $(OBJS) $(LDFLAGS)-o $(NAME)
$(NAME2):	$(OBJS2)
			$(CC) $(OBJS2) -o $(NAME2)

%.o: %.c 	$(INC)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS2)

fclean: 	clean
			$(RM) $(NAME) $(NAME2)

re:			clean all

bonus:		$(NAME2)