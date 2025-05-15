NAME = interfaces
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
INCLUDE = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

OBJS_DIR = objects
OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.cpp=.o}}

DEPS_DIR = dependances
DEPS = ${addprefix ${DEPS_DIR}/, ${OBJS:.o=.d}}

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -MMD -MP

${OBJS_DIR}/%.o: %.cpp ${INCLUDE}
		mkdir -p ${OBJS_DIR} ${DEPS_DIR}
		${CXX} ${CFLAGS} -c $< -o $@ -MF ${DEPS_DIR}/$*.d

${NAME}: ${OBJS} ${INCLUDE} Makefile
		${CXX} ${CFLAGS} ${OBJS} -I ./ -o $@

all: ${NAME}

clean:
		rm -rf ${OBJS_DIR} ${DEPS_DIR}

fclean: clean;
		rm -f ${NAME}

-include ${DEPS}

re: fclean all

.PHONY: all clean fclean re
