SRCS = ./srcs/push_swap/push_swap.c \
		./srcs/push_swap/control_functions.c \
		./srcs/push_swap/utils.c \
		./srcs/push_swap/five_sort.c \
		./srcs/push_swap/sort_functions.c \
		./srcs/push_swap/ft_sort.c
SRCBS =
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_LIBFT = ./srcs/libary/ft_libft/libft.a
RM = rm -rf

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCS) $(FT_LIBFT) -o $(NAME)
	@echo "************************"
	@echo "   PUSH SWAP CREATED"
	@echo "************************"


bonus : $(SRCBS) $(FT_PRINTF) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCBS) $(FT_LIBFT) -o $(NAME)
	@echo "************************"
	@echo "    CHECKER CREATED"
	@echo "************************"

$(FT_PRINTF) :
	@make -C ./srcs/libary/ft_printf

$(FT_LIBFT) :
	@make -C ./srcs/libary/ft_libft

clean:
	@make fclean -C ./srcs/libary/ft_printf
	@make fclean -C ./srcs/libary/ft_libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./srcs/libary/ft_printf
	@make fclean -C ./srcs/libary/ft_libft

re: fclean all

.PHONY: all bonus clean fclean re .c.o