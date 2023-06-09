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

void	calculate_steps_mini(t_data *data, int i)
{
	if (data->s_b->mini <= data->s_b->size / 2)
	{
		if (i <= data->s_a->size / 2)
		{
			printf("%d\n", data->s_a->num[i]);
			if (data->s_b->maxi <= i + 1)
				data->steps[i] = i + 1;
			else
				data->steps[i] = data->s_b->maxi;
		}
	}
}
//14 49 17 40 29 10 11 27 - 19 47
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
		if (data->s_a->num[i] < data->s_b->num[data->s_b->mini])
			calculate_steps_mini(data, i);
		i++;
	}
}

void	calculate_steps(t_data *data)
{
	bmax(data);
	bmin(data);
	find_cheapest(data);
	for (int i = 0; i <= data->s_a->size; ++i) {
		printf("%d - %d\n", data->s_a->num[i], data->steps[i]);
	}
	printf("----\n");
}