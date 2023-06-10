SRCS = ./srcs/mandatory_part/push_swap.c \
		./srcs/mandatory_part/utils.c \
		./srcs/mandatory_part/check_functions.c \
		./srcs/mandatory_part/sorting_functions.c \
		./srcs/mandatory_part/choose_sort.c \
		./srcs/mandatory_part/calculate_steps.c \
		./srcs/mandatory_part/fsort.c
SRCBS =
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ./srcs/libary/ft_printf/libftprintf.a
FT_LIBFT = ./srcs/libary/ft_libft/libft.a
RM = rm -rf

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(FT_PRINTF) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCS) $(FT_PRINTF) $(FT_LIBFT) -o $(NAME)
	@echo "************************"
	@echo "   PUSH SWAP CREATED"
	@echo "************************"


bonus : $(SRCBS) $(FT_PRINTF) $(FT_LIBFT)
	@gcc $(CFLAGS) $(SRCBS) $(FT_PRINTF) $(FT_LIBFT) -o $(NAME)
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