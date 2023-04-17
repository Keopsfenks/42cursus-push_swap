/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:12:07 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/17 06:42:39 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_pivot(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size / 2)
	{
		i++;
	}
	return (stack->num[i]);
}

int	min_value_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->size)
	{
		if (stack->num[i] < stack->pivot)
			return (1);
		i++;
	}
	return (0);
}

void	min_number_push_b(t_data *data)
{
	data->s_a->pivot = select_pivot(data->s_a);
	while (min_value_check(data->s_a))
	{
		if (data->s_a->num[data->s_a->size] < data->s_a->pivot)
			pb(data);
		else
			ra(data, 1);
	}
}

void	cost_calculation(t_stack *stack, int i, int j)
{
	int	cost;
	(void )stack;
	cost = i - j;
}

void	quick_sort(t_data *data)
{
	int	i;
	int	j;

	data->s_a->pivot = select_pivot(data->s_a);
	data->s_b->pivot = select_pivot(data->s_b);
	i = 0;
	j = -1;
	while (i < 6)
	{
		if (data->s_a->num[i] < data->s_a->pivot)
		{
			j++;
			cost_calculation(data->s_a, i, j);
		}
		i++;
	}
}