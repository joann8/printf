# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 09:41:42 by jacher            #+#    #+#              #
#    Updated: 2020/12/05 22:31:48 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = includes

SRCS = srcs/ft_putadd.c \
srcs/ft_strdup.c \
srcs/ft_itoa_printf.c \
srcs/ft_strlen.c \
srcs/ft_putstr_fd.c \
srcs/ft_support2.c \
srcs/ft_support.c \
srcs/ft_string.c \
srcs/ft_char.c \
srcs/ft_parsing_help.c \
srcs/ft_atoi_printf.c \
ft_printf.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = clang

NAME = libftprintf.a

LIB	= ar -rcs

RM = rm -f

.c.o:
	${CC} ${FLAGS} -I${INC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${INC}/libft.h printf.h 
	${LIB} ${NAME} ${OBJS}		
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re 
