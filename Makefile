NAME = push_swap

INC = -I$(LIB_DIR)

LIB_DIR = libft

LIB_A = libft/libft.a

SRCS = main.c lst.c operations1.c operations2.c operations3.c utils.c sort.c checker.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	${CC} -g ${FLAGS} -c $< -o $@ 

all: makelib $(NAME)

$(NAME): $(OBJS) $(LIB_A) Makefile push_swap.h
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB_A)

makelib:
	@make -C $(LIB_DIR) bonus

clean:
	make -C $(LIB_DIR) clean
	rm -rvf $(OBJS) 