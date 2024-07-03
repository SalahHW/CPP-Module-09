# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 14:48:31 by sbouheni          #+#    #+#              #
#    Updated: 2024/07/03 14:48:34 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	PmergeMe

CXX						=	c++ -Wall -Wextra -Werror -std=c++98 -g

INCLUDE_DIR				=	include/
SRCS_DIR				=	source/
OBJ_DIR					=	obj/

SRCS					=	main.cpp											\
							PmergeMe.cpp

OBJS        			=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o			:	$(SRCS_DIR)%.cpp | $(OBJ_DIR)
							$(CXX) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)				:
							mkdir -p $(OBJ_DIR)

clean					:
							rm -rf $(OBJ_DIR)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re
