NAME = push_swap

BONUS = checker

SRCS = ./srcs/mandatory_part/push_swap.c \
		./srcs/mandatory_part/sorting_functions.c \
		./srcs/mandatory_part/quick_short.c

BONUS_SRCS =

PRINTF = ./srcs/libary/ft_printf/libftprintf.a

LIBFT = ./srcs/libary/ft_libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./srcs/libary/ft_printf/
	@make -C ./srcs/libary/ft_libft/
	@$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)
	@echo "PUSH_SWAP CREATED"

clean:
	@make fclean -C ./srcs/libary/ft_printf/
	@make fclean -C ./srcs/libary/ft_libft/

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re: fclean all

bonus: $(BONUS)

$(BONUS): $(BONUS_SRCS)
	@make -C ./srcs/libary/ft_printf/
	@make -C ./srcs/libary/ft_libft/
	@$(CC) $(CFLAGS) $(BONUS_SRCS) $(PRINTF) $(LIBFT) -o $(BONUS)
	@echo "CHECKER CREATED!"

.PHONY: all fclean clean re