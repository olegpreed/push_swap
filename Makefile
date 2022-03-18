NAME = push_swap

NAME_B = ./checker/checker

INC = -I$(LIB_DIR)

LIB_DIR = libft

LIB_A = libft/libft.a

SRCS_M = main.c

SRCS = parser.c lst.c operations1.c operations2.c operations3.c utils.c sort.c parser2.c

SRCS_B = ./checker/main_bonus.c ./checker/input_bonus.c \
		./checker/operations1_bonus.c ./checker/operations2_bonus.c ./checker/operations3_bonus.c

OBJS = $(SRCS:%.c=%.o)

OBJS_B = $(SRCS_B:%.c=%.o)

OBJS_M = $(SRCS_M:%.c=%.o)

FLAGS = -g -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	${CC} -g ${FLAGS} -c $< -o $@ 

all: makelib $(NAME)

bonus: $(OBJS_B)
	$(CC) $(FLAGS) $(OBJS_B) $(OBJS) -o $(NAME_B) $(LIB_A)

$(NAME): $(OBJS_M) $(OBJS) $(LIB_A) Makefile push_swap.h
	$(CC) $(FLAGS) $(OBJS_M) $(OBJS) -o $(NAME) $(LIB_A)

makelib:
	@make -C $(LIB_DIR) bonus

clean:
	make -C $(LIB_DIR) clean
	rm -rvf $(OBJS) $(OBJS_B) $(OBJS_M)

fclean: clean
	rm -rf $(NAME) $(NAME_B) $(LIB_A)

re: fclean all