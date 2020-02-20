SRCS     = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INCLUDE    = includes/
NAME    = libft.a
OBJS    = ${SRCS:.c=.o}
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
RM        = rm -f

.c.o:
	        ${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}

${NAME}:    ${OBJS}
	            ar rc ${NAME} ${OBJS}

all:        ${NAME}

clean:
	            ${RM} ${OBJS}

fclean:        clean
	            ${RM} ${NAME}

re:            fclean    all

.PHONY:        all clean fclean re
