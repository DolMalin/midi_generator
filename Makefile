SRC_FILES =	main.c\
			midi_format.c\
			notes_generation.c

SRCS =		${addprefix srcs/,${SRC_FILES}}

OBJS =		${SRCS:.c=.o}

LIB		= ./megalib/libft.a

NAME =		midi

HEADERS =	./srcs/main.h

CFLAGS =	-Wall -Wextra -Werror

CC =		gcc

%.o: 		%.c ${HEADERS} Makefile ${LIB}
			${CC} ${CFLAGS} -c $< -o $@

all:		library ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB}

library:
			make -C ./megalib

clean:
			rm -f ${OBJS}
			make clean -C ./megalib

fclean:
			rm -f ${NAME} ${OBJS}
			make fclean -C ./megalib

re:			fclean all

.PHONY:	all clean fclean re library