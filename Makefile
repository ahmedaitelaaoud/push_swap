# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 11:04:50 by aait-ela          #+#    #+#              #
#    Updated: 2025/12/27 12:35:06 by aait-ela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= check_args.c \
		ft_split.c \
		pars_init.c \
		stack_utils.c \
		stack_init.c \
		push.c \
		swap.c \
		rotate.c \
		rev_rotate.c \
		sort_tiny.c \
		sort_big.c \
		main.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

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
