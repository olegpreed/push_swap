# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 20:16:46 by preed             #+#    #+#              #
#    Updated: 2022/03/20 15:53:56 by oleg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
		ft_isascii.c	ft_isprint.c	ft_strlen.c \
		ft_memset.c		ft_bzero.c		ft_memcpy.c \
		ft_memmove.c	ft_strlcpy.c	ft_toupper.c \
		ft_tolower.c	ft_strchr.c		ft_strrchr.c \
		ft_strncmp.c	ft_memchr.c		ft_memcmp.c \
		ft_strnstr.c	ft_atoi.c		ft_calloc.c \
		ft_strdup.c		ft_strlcat.c \
		ft_substr.c		ft_strjoin.c	ft_strtrim.c \
		ft_split.c		ft_itoa.c		ft_strmapi.c \
		ft_striteri.c	ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_B =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c \

OBJS = ${SRCS:%.c=%.o}

OBJS_B = ${SRCS_B:%.c=%.o}

D_FILES = ${SRCS:%.c=%.d} ${SRCS_B:%.c=%.d}

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror 

.PHONY: all clean fclean re bonus

all: ${NAME}

%.o: %.c
	${CC} -g ${FLAGS} -c $< -o $@ -MMD

-include ${D_FILES}

${NAME}: ${OBJS} ${HEADER}
	ar rcs ${NAME} $?

bonus: all
	@make OBJS="${OBJS_B}" all

clean:
	@${RM} ${OBJS} ${OBJS_B} ${D_FILES}

fclean: clean
	@${RM} ${NAME}

re: fclean all
