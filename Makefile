SRCS = ./srcs/push_swap/push_swap.c \
		./srcs/push_swap/ft_parse.c \
		./srcs/push_swap/utils.c \
		./srcs/push_swap/utils_2.c \
		./srcs/push_swap/five_sort.c \
		./srcs/push_swap/sort_functions.c \
		./srcs/push_swap/sort_functions2.c \
		./srcs/push_swap/sort_functions3.c \
		./srcs/push_swap/ft_sort.c \
		./srcs/push_swap/ft_sortm.c \
		./srcs/push_swap/ft_sorto.c \
		./srcs/push_swap/calculate_steps.c

SRCBS = ./srcs/checker/checker.c \
		./srcs/checker/ft_parse.c \
		./srcs/checker/sort_functions.c \
		./srcs/checker/sort_functions2.c \
		./srcs/checker/sort_functions3.c \
		./srcs/checker/utils.c
NAME = push_swap
NAME_CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_LIBFT = ./srcs/libary/ft_libft/libft.a
FT_GET_NEXT_LINE = ./srcs/libary/ft_get_next_line/get_next_line.c ./srcs/libary/ft_get_next_line/get_next_line_utils.c
RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCS) $(FT_LIBFT) -o $(NAME)
	@echo "************************"
	@echo "   PUSH SWAP CREATED"
	@echo "************************"


bonus : $(SRCBS) $(FT_GET_NEXT_LINE) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCBS) $(FT_GET_NEXT_LINE) $(FT_LIBFT) -o $(NAME_CHECKER)
	@echo "************************"
	@echo "    CHECKER CREATED"
	@echo "************************"

$(FT_LIBFT) :
	@make -C ./srcs/libary/ft_libft

clean:
	@make fclean -C ./srcs/libary/ft_libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_CHECKER)
	@make fclean -C ./srcs/libary/ft_libft

re: fclean all

.PHONY: all bonus clean fclean re .c.o