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

void	add_numbers_to_list(t_data *data, char *numbers)
{
	int	i;
	char **nb;
	int	numb;
	t_data *tmp;

	i = 1;
	tmp = ft_calloc(sizeof (t_data), 1);
	tmp->stack_a = ft_calloc(sizeof (t_list), 1);
	nb = ft_split(numbers, ' ');
	data->stack_a->content = ft_atoi(nb[0]);
	while (nb[i])
	{
		tmp->stack_a = ft_calloc(sizeof (t_list), 1);
		numb = ft_atoi(nb[i]);
		tmp->stack_a->content = numb;
		data->stack_a->next = tmp->stack_a;
		tmp->stack_a = tmp->stack_a->next;
		data->stack_a->next
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*numbers;
	int		i;

	data = ft_calloc(sizeof (t_data), 1);
	data->stack_a = ft_calloc(sizeof (t_list), 1);
	data->stack_b = ft_calloc(sizeof (t_list), 1);
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
		add_numbers_to_list(data, numbers);
	}
	int d = 0;
	while(data->stack_a != NULL)
	{
		printf("%d\n", data->stack_a->content);
		data->stack_a = data->stack_a->next;
		d++;
	}
}
