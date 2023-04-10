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

void	add_numbers_to_list(t_list *stack_a, char **numbers, int i)
{
	if(numbers[i])
	{
		stack_a->content = ft_atoi(numbers[i]);
		if(numbers[i + 1])
			stack_a->next = ft_calloc(sizeof(t_list), 1);
		i++;
		add_numbers_to_list(stack_a->next, numbers, i);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*numbers;
	char 	**nb;
	int		i;

	data = ft_calloc(sizeof (t_data), 1);
	data->stack_a = ft_calloc(sizeof(t_list), 1);
	i = 1;
	if (ac > 1)
	{
		numbers = ft_calloc(ft_strlen(av[i]), 1);
		while (av[i])
		{
			numbers = ft_strjoin(numbers, av[i]);
			numbers = ft_strjoin(numbers, " ");
			i++;
		}
		nb = ft_split(numbers, ' ');
		add_numbers_to_list(data->stack_a, nb, 0);
	}
	while(data->stack_a != NULL)
	{
		printf("%d\n", data->stack_a->content);
		data->stack_a = data->stack_a->next;
	}
}
