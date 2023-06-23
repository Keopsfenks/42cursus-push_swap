/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:52:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/16 19:55:15 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_data *data)
{
	min_stack(data->b);
	if (data->b->mini < data->b->size / 2)
	{
		while (data->b->mini != data->b->size - 1)
		{
			rb(data, 1);
			min_stack(data->b);
		}
	}
	else
	{
		while (data->b->mini != data->b->size - 1)
		{
			rrb(data, 1);
			min_stack(data->b);
		}
	}
}

static void	ft_sort(t_data *data)
{
	data->steps = ft_calloc(sizeof(int), data->a->size);
	pb(data);
	pb(data);
	while (0 < data->a->size)
	{
		find_cheapest(data);
		ft_start(data);
	}
	ft_rotate(data);
	while (data->b->size != 0)
		pa(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (ac > 1)
	{
		ft_parse(data, ac, av); //leak var
		if (data->a->size < 6)
			five_sort(data);
		else
			ft_sort(data);
	}
	else
		return (0);
}
