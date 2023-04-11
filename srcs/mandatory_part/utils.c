#include "push_swap.h"
void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

int	ft_lstsize(t_list *stack)
{
	int i = 0;

	t_list *tmp = stack;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int ft_lstlast(t_list *stack)
{
	int i = 0;

	t_list *tmp = stack;
	while(tmp != NULL)
	{
		i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lstlast_index(t_list *stack, int value)
{
	if(stack != NULL)
	{
		if (stack->next == NULL)
			stack->content = value;
		ft_lstlast_index(stack->next, value);
	}
}

void	ft_lst_rotate(t_list *stack, int value)
{
	if(stack != NULL)
	{
		if (stack->next == NULL)
			stack->content = value;
		else
			stack->content = stack->next->content;
		ft_lst_rotate(stack->next, value);
	}
}

void	ft_lst_rotate_reverse(t_list *stack, int value)
{
	int	tmp;

	if (stack->next != NULL)
	{
		tmp = stack->next->content;
		stack->next->content = stack->content;
		stack->content = tmp;
		ft_lst_rotate_reverse(stack->next, value);
	}
}

long int	ft_long_atoi(const char *str)
{
	long int	number;
	int			rule;

	number = 0;
	rule = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		rule = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		number = (number * 10) + (*str - '0') * rule;
		str++;
	}
	return (number);
}