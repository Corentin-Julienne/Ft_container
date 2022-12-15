# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 16:33:33 by cjulienn          #+#    #+#              #
#    Updated: 2022/12/15 16:27:41 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colors set
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
UNDERLINE	= \e[4m
RESET		= \033[0m
END			= \e[0m

NAME = ft_containers

SRCS = ./srcs/tests.cpp \
	   ./srcs/test_utils/colors.cpp \
	   ./srcs/test_utils/other.cpp \
	   ./srcs/vector/vector_tests.cpp \
	   ./srcs/map/map_tests.cpp \
	#    ./srcs/vector/vector_speedtests.cpp \
	#    ./srcs/map/map_speedtests.cpp \
	#    ./srcs/maptree_tests.cpp

OBJS = $(SRCS:.cpp=.o)

CC := c++
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I Includes

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re #ok
