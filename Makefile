SRC = factorization.c
OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wextra -Wall -Werror

NAME = factorization


all :		${NAME}

.c.o :		${SRC}
				${CC} ${CFLAGS} -c ${SRC} -o ${<:.c=.o}

${NAME} :	${OBJ}
				${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
				rm -f ${OBJ}

fclean :	clean
				rm -f ${NAME}

re : 		fclean all
