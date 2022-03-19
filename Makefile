# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 17:13:03 by oleg              #+#    #+#              #
#    Updated: 2022/03/20 00:25:30 by oleg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          = push_swap
NAME_B        = checker

CC            = gcc
FLAGS         = -g -Wall -Wextra -Werror

LIBFT         = libft/libft.a
INC           = includes/
HEADER		  = push_swap.h checker_bonus.h	
HEADERS       = $(addprefix $(INC), $(HEADER))

LIB_DIR       = libft/
PUSH_SWAP_DIR = push_swap/
CHECKER_DIR   = checker/
OBJS_DIR      = objs/
SRCS_DIR      = src/
    
MAIN_SRC      = main.c
PUSH_SWAP_SRC = parser.c parser2.c operations1.c operations2.c operations3.c lst.c utils.c sort.c
CHECKER_SRC   = main_bonus.c input_bonus.c operations1_bonus.c operations2_bonus.c operations3_bonus.c

MAIN_OBJ      = $(addprefix $(OBJS_DIR)$(PUSH_SWAP_DIR),$(MAIN_SRC:%.c=%.o))
PUSH_SWAP_OBJ = $(addprefix $(OBJS_DIR)$(PUSH_SWAP_DIR),$(PUSH_SWAP_SRC:%.c=%.o))
CHECKER_OBJ   = $(addprefix $(OBJS_DIR)$(CHECKER_DIR),$(CHECKER_SRC:%.c=%.o))

$(OBJS_DIR)$(PUSH_SWAP_DIR)%.o: $(SRCS_DIR)$(PUSH_SWAP_DIR)%.c
	${CC} ${FLAGS} -c $< -o $@ -I$(INC)

$(OBJS_DIR)$(CHECKER_DIR)%.o: $(SRCS_DIR)$(CHECKER_DIR)%.c
	${CC} ${FLAGS} -c $< -o $@ -I$(INC)

.PHONY: all clean fclean re bonus

all: makelib $(HEADERS) $(NAME)

$(OBJS_DIR):
		@mkdir -p $@

$(OBJS_DIR)$(CHECKER_DIR): $(OBJS_DIR)
		@mkdir -p $@

$(OBJS_DIR)$(PUSH_SWAP_DIR): $(OBJS_DIR)
		@mkdir -p $@

$(NAME): $(OBJS_DIR)$(PUSH_SWAP_DIR) $(PUSH_SWAP_OBJ) $(MAIN_OBJ) $(LIBFT) Makefile
	$(CC) $(FLAGS) $(MAIN_OBJ) $(PUSH_SWAP_OBJ) -o $(NAME) $(LIBFT) -I$(INC)

makelib:
	@make -C $(LIB_DIR) bonus --no-print-directory

bonus: $(NAME_B)

$(NAME_B): $(OBJS_DIR)$(CHECKER_DIR) $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT) Makefile
	$(CC) $(FLAGS) $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) -o $(NAME_B) $(LIBFT) -I$(INC)

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	rm -rvf $(OBJS_DIR)

fclean: clean
	rm -rvf $(NAME) $(NAME_B) $(LIBFT)

re: fclean all