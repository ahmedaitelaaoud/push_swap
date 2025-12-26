# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 11:04:50 by aait-ela          #+#    #+#              #
#    Updated: 2025/12/26 18:07:02 by aait-ela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/parsing/check_args.c \
		srcs/parsing/ft_split.c \
		srcs/parsing/pars_init.c \
		srcs/stack/stack_utils.c \
		srcs/commands/push.c \
		srcs/commands/swap.c \
		srcs/main.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I includes

NAME	= push_swap

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
