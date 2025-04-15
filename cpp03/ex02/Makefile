NAME = FragTrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INCLUDE = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

.cpp.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${INCLUDE} Makefile
		${CC} ${CFLAGS} -I ./ -o $@ ${OBJS}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
