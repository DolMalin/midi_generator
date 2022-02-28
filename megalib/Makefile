SRC_FREE	=	ft_free_tab.c

SRC_PRINTF	= 	ft_printf.c \
				ft_prints.c \
				ft_prints_2.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putunbr_fd.c

SRC_GNL		=	get_next_line.c

SRC_LST		=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

SRC_MEM		=	ft_bzero.c \
				ft_calloc.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c

SRC_STR		=	ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strjoin_multi.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

SRC_ERR		=	ft_close.c \
				ft_access.c \
				ft_dup.c \
				ft_dup2.c \
				ft_execve.c \
				ft_fork.c \
				ft_malloc.c \
				ft_open.c \
				ft_pipe.c \
				ft_waitpid.c

SRCS = ${addprefix free/, ${SRC_FREE}} \
${addprefix ft_printf/, ${SRC_PRINTF}} \
${addprefix get_next_line/, ${SRC_GNL}} \
${addprefix lst/, ${SRC_LST}} \
${addprefix mem/, ${SRC_MEM}} \
${addprefix strs/, ${SRC_STR}} \
${addprefix errors/, ${SRC_ERR}}
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
HEADERS	= libft.h ft_printf/printf.h get_next_line/get_next_line.h
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HEADERS} Makefile
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS} ${HEADERS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
