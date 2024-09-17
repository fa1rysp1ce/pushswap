# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junruh <junruh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 18:39:45 by junruh            #+#    #+#              #
#    Updated: 2024/09/10 17:59:37 by junruh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap


LIB_DIR = ./libftplus/
LIB = libftplus.a
LIB_P = $(addprefix $(LIB_DIR), $(LIB))

SRCS = main.c \
		helpers.c \
		helpers2.c \
		actions1.c \
		actions2.c \
		sort.c \
		push_b.c

OBJS = $(SRCS:.c=.o)


CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I. -I$(LIB_DIR)


.PHONY: all clean fclean re

all: $(NAME)

$(LIB_P):
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB) .

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(LIB_P)
	$(CC) $(OBJS) $(LIB_P) -L$(LIB_DIR) -lftplus -o $(NAME)

clean:
	make fclean -C $(LIB_DIR)
	$(RM) $(OBJS) $(LIB)

fclean: clean 
	$(RM) $(NAME)

re: fclean all	