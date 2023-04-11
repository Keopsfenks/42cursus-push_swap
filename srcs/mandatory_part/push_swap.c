/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:30:21 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/04 13:14:36 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_numbers_to_list(t_list *stack, char **numbers, int i)
{
	if(numbers[i])
	{
		stack->content = ft_atoi(numbers[i]);
		if(numbers[i + 1])
			stack->next = ft_calloc(sizeof(t_list), 1);
		i++;
		add_numbers_to_list(stack->next, numbers, i);
	}
}

int	main(int ac, char **av)
{
	t_data *data;
	char *numbers;
	int i;

	data = ft_calloc(sizeof(t_data), 1);
	data->stack_a = ft_calloc(sizeof(t_list), 1);
	data->stack_b = NULL;
	i = 1;
	if (ac > 1) {
		numbers = ft_calloc(ft_strlen(av[i]), 1);
		while (av[i]) {
			numbers = ft_strjoin(numbers, av[i]);
			numbers = ft_strjoin(numbers, " ");
			i++;
		}
		data->numbers = ft_split(numbers, ' ');
		check_all(data);
	}
	else
		error_print("ARGUMENT ERROR");
}
