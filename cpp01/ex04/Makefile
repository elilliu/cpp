NAME = mySed
SRCS = main.cpp
INCLUDE = mySed.hpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

.cpp.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${INCLUDE}
		${CC} ${CFLAGS} -I ./ -o $@ ${OBJS}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

