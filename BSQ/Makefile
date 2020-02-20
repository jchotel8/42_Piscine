# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchotel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 19:45:39 by jchotel           #+#    #+#              #
#    Updated: 2019/08/21 23:28:55 by jchotel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
RM_COMMAND = rm -f
OPTIONS = -I${PATH_HEADERS}
FLAGS = -Wall -Wextra -Werror
SRCS = ${PATH_SRCS}/main.c ${PATH_SRCS}/display_text.c ${PATH_SRCS}/read_map.c ${PATH_SRCS}/ft_strdup.c ${PATH_SRCS}/display_map.c ${PATH_SRCS}/ft_split.c ${PATH_SRCS}/fill_map.c ${PATH_SRCS}/verifications_map.c   ${PATH_SRCS}/ft_strjoin.c  ${PATH_SRCS}/ft_putstr.c ${PATH_SRCS}/ft_putchar.c ${PATH_SRCS}/ft_strlen.c ${PATH_SRCS}/ft_swap.c ${PATH_SRCS}/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: ${OBJS}
		${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${COMPILER_COMMAND} ${FLAGS} ${OBJS} -o ${NAME}

clean:
		${RM_COMMAND} ${OBJS}

fclean: clean
		${RM_COMMAND} ${NAME}

re: fclean all
