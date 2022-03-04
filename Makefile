NAME = push_swap

INC = -I$(LIB_DIR)

LIB_DIR = libft

LIB_A = libft/libft.a

SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: makelib $(NAME)

$(NAME): $(OBJS) $(LIB_A)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB_A)

makelib:
	@make -C $(LIB_DIR)

clean:
	make -C $(LIB_DIR) clean
	rm -rvf $(OBJS) $(NAME)