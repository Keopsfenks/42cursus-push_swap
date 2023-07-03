/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:25:53 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/22 17:32:44 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_number(t_stack *stack, int nbr)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->num[i] == nbr)
			return (i);
	}
	return (-1);
}

int	max_position(t_stack *stack, int *positon, int ind)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < ind)
	{
		if (positon[index] < positon[i])
			index = i;
		i++;
	}
	return (find_number(stack, positon[index]));
}

int	find_the_position_number(t_stack *stack, int anum)
{
	int	*position;
	int	i;
	int	index;

	position = ft_calloc(sizeof(int), stack->size + 2);
	i = -1;
	index = 0;
	while (++i < stack->size)
	{
		if (anum > stack->num[i])
		{
			position[index] = stack->num[i];
			index++;
		}
	}
	index = max_position(stack, position, index);
	free(position);
	return (index);
}
