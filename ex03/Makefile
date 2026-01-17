# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 16:47:57 by JuHyeon           #+#    #+#              #
#    Updated: 2026/01/17 16:26:04 by juhyeonl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude
SHADOWFLAG = -Wall -Wextra -Werror -std=c++98 -Wshadow -Iinclude
RM		= rm -rf

SRC_DIR	= ./src
OBJ_DIR	= ./obj

SRC = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/ClapTrap.cpp \
		$(SRC_DIR)/ScavTrap.cpp \
		$(SRC_DIR)/FragTrap.cpp \
		$(SRC_DIR)/DiamondTrap.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

shadow: fclean
	@make $(NAME) CFLAGS="$(SHADOWFLAG)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Cleaned up all object files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaned up $(NAME)"

re: fclean all

.PHONY: all clean fclean re% 