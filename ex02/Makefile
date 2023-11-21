# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agengemb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:01:24 by agengemb          #+#    #+#              #
#    Updated: 2023/11/21 15:30:34 by agengemb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -MMD
NAME = first_cog
SRC= Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
DEP= ${OBJ:.o=.d}

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
