# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 16:33:33 by cjulienn          #+#    #+#              #
#    Updated: 2022/11/29 17:00:19 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Containers # change this ?

SRCS = ./tests/my_main.cpp \
	   ./tests/Colors.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
