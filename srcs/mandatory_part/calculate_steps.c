/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:52:18 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/09 21:52:24 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bmax(t_data *data)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i <= data->s_b->size)
	{
		if (data->s_b->num[index] < data->s_b->num[i])
			index = i;
		i++;
	}
	data->s_b->maxi = index;
}

void	bmin(t_data *data)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i <= data->s_b->size)
	{
		if (data->s_b->num[index] > data->s_b->num[i])
			index = i;
		i++;
	}
	data->s_b->mini = index;
}

void	calculate_steps_other(t_data *data, int i)
{
	if (data->s_b->maxi <= data->s_b->size + 1 / 2)
	{
		if (i <= data->s_a->size / 2)
		{
			if (i == 0)
			{
				if (data->s_b->maxi > i)
					data->steps[i] += 1;
			}
			else if (data->s_b->maxi <= i + 1)
				data->steps[i] = i + 1;
			else
				data->steps[i] = data->s_b->maxi;
		}
		else
			data->steps[i] += data->s_b->maxi;
	}
	else if (data->s_b->maxi > data->s_b->size + 1)
		data->steps[i] = data->s_b->size + 1 - data->s_b->maxi;
}

void	find_cheapest(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->s_a->size)
	{
		if (i <= data->s_a->size / 2)
			data->steps[i] = i + 1;
		else if (i > data->s_a->size / 2)
			data->steps[i] = (data->s_a->size - i) + 2;
		calculate_steps_other(data, i);
		i++;
	}
}

void	foundthe_cheapest(t_data *data)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	while (i <= data->s_a->size)
	{
		if (data->steps[index] > data->steps[i])
			data->moveindex = index;
		i++;
	}
}

void	calculate_steps(t_data *data)
{
	bmax(data);
	bmin(data);
	find_cheapest(data);
	foundthe_cheapest(data);
}