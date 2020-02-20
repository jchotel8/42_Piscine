# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 19:45:39 by llaurent          #+#    #+#              #
#    Updated: 2019/08/18 20:03:10 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
RM_COMMAND = rm -f
OPTIONS = -I${PATH_HEADERS}
FLAGS = -Wall -Wextra -Werror
SRCS = ${PATH_SRCS}/ft_split.c ${PATH_SRCS}/arguments.c ${PATH_SRCS}/ft_itoa.c ${PATH_SRCS}/ft_strstr.c ${PATH_SRCS}/main.c ${PATH_SRCS}/read_file.c ${PATH_SRCS}/rush02.c ${PATH_SRCS}/verif_dico.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: ${OBJS}
		${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${COMPILER_COMMAND} ${FLAGS} ${OBJS} -o ${NAME} -Lincludes -lft

clean:
		${RM_COMMAND} ${OBJS}

fclean: clean
		${RM_COMMAND} ${NAME}

re: fclean all
