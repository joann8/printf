# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 09:41:42 by jacher            #+#    #+#              #
#    Updated: 2020/12/12 20:13:59 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_add.c \
srcs/ft_char.c \
srcs/ft_hexa.c \
srcs/ft_int.c \
srcs/ft_int_utils.c \
srcs/ft_itoa_printf.c \
srcs/ft_parsing_help.c \
srcs/ft_percent.c \
srcs/ft_putadd.c \
srcs/ft_string.c \
srcs/ft_utils.c \
srcs/ft_utils_bis.c \
ft_printf.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = clang

NAME = libftprintf.a

LIB	= ar -rcs

RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} pf.h 
	${LIB} ${NAME} ${OBJS}		
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re 
