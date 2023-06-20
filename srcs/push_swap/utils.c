/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:27:53 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/20 02:15:35 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

char	*ps_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ft_strlcpy(ptr + i, s2, (ft_strlen(s2) + 1));
	free (s1);
	return (ptr);
}

int	ps_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48) * sign;
		if (result > 2147483647 || result < -2147483648)
			error();
		i++;
	}
	return ((int)result);
}

int	min_stack(t_stack *stack)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i <= stack->size)
	{
		if (stack->num[index] > stack->num[i])
			index = i;
		i++;
	}
	stack->mini = index;
	return (index);
}

int	max_stack(t_stack *stack)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i <= stack->size)
	{
		if (stack->num[index] < stack->num[i])
			index = i;
		i++;
	}
	stack->maxi = index;
	return (index);
}

int	find_the_spot(t_stack *stack, int a)
{
	int	i;
	int	biggest_small;

	i = -1;
	biggest_small = min_stack(stack);
	while (++i < stack->size)
	{
		if (stack->num[i] < a)
		{
			if (stack->num[i] >= stack->num[biggest_small])
				biggest_small = i;
		}
	}
	if (a < stack->num[min_stack(stack)])
		return (min_stack(stack));
	return (biggest_small);
}

void	stack_moves_a(t_data *data, t_sort *calc, int i)
{
	if (i <= data->a->size / 2)
		calc->a = i;
	else if (i > data->a->size / 2)
		calc->ar = data->a->size - i;
}

void	stack_moves_a_2(t_data *data, t_sort *calc, int i)
{
	if (i <= data->a->size / 2)
		calc->a++;
	else if (i > data->a->size / 2)
		calc->ar++;
}

void	stack_moves_b(t_data *data, t_sort *calc, int i)
{
	if (i <= data->a->size / 2)
		calc->b = i;
	else if (i > data->a->size / 2)
		calc->br = data->a->size - i;
}

void	stack_moves_b_2(t_data *data, t_sort *calc, int i)
{
	if (i <= data->b->size / 2)
		calc->b++;
	else if (i > data->b->size / 2)
		calc->br++;
}

int	stack_moves_i(t_stack *stack, int i)
{
	if (i <= stack->size / 2)
		return (i);
	else if (i > stack->size / 2)
		return (stack->size - i);
	return (0);
}

void	moves_init(t_sort *calc)
{
	calc->a = 0;
	calc->b = 0;
	calc->ar = 0;
	calc->br = 0;
}

int	take_cheapest(t_data *data)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < data->a->size)
	{
		if (data->steps[i] < data->steps[index])
			index = i;
		i++;
	}
	data->cheapest = index;
	return (index);
}