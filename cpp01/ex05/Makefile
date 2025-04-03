NAME = harl
SRCS = main.cpp Harl.cpp
INCLUDE = Harl.hpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wextra -Werror -Wall -std=c++98

.cpp.o:
		${CC} ${CFLAGF} -c $< -o $@

${NAME}: ${OBJS} ${INCLUDE} Makefile
		${CC} ${CFLAGS} -I ./ -o $@ ${OBJS}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONE: all clean fclean re
