NAME = gnl.a
SRCS = get_next_line.c\
		get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
