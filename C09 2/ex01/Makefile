NAME = libft.a
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
RM_COMMAND = rm -f
FLAGS = -Wall -Wextra -Werror
SRCS = ${PATH_SRCS}/ft_putchar.c ${PATH_SRCS}/ft_putstr.c ${PATH_SRCS}/ft_strcmp.c ${PATH_SRCS}/ft_strlen.c ${PATH_SRCS}/ft_swap.c
INCLUDES = -I${PATH_HEADERS}/ft.h
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: ${OBJS}
		${COMPILER_COMMAND} ${INCLUDES} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${COMPILER_COMMAND} ${FLAGS} ${OBJS} -o ${NAME} -Lincludes -lft

clean:
		${RM_COMMAND} ${OBJS}

fclean: clean
		${RM_COMMAND} ${NAME}

re: fclean all