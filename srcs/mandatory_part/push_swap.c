/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:03:50 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/17 06:41:44 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_numbers_to_int(t_data *data)
{
	int	i;

	i = 0;
	while (data->nb[i])
		i++;
	data->s_a->size = i - 1;
	data->s_b->size = -1;
	data->s_a->num = ft_calloc(sizeof(int), data->s_a->size);
	data->s_b->num = ft_calloc(sizeof(int), data->s_a->size);
	i = 0;
	while (i <= data->s_a->size)
	{
		data->s_a->num[i] = ft_atoi(data->nb[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*numbers;
	int		i;

	i = 1;
	data = ft_calloc(sizeof(t_data), 1);
	data->s_a = ft_calloc(sizeof(t_stack), 1);
	data->s_b = ft_calloc(sizeof(t_stack), 1);
	if (ac > 1)
	{
		numbers = ft_calloc(ft_strlen(av[i]), 1);
		while (av[i])
		{
			numbers = copy(numbers, av[i]);
			numbers = copy(numbers, " ");
			i++;
		}
		data->nb = ft_split(numbers, ' ');
		check_all(data);
		choose_sort(data);
	}
	else
		error_print("ARGUMENT ERROR!");
}
