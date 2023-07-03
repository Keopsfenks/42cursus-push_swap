/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:54:10 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 06:08:38 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_m(t_data *data)
{
	int	nbri;

	nbri = max_stack(data->b);
	if (data->cheapest == data->a->size - 1
		&& nbri == data->b->size -1
		&& data->cheapest > 1)
	{
		rrr(data);
		data->cheapest = 0;
	}
	else if (data->cheapest == data->a->size - 1
		&& data->cheapest > 1)
	{
		rra(data, 1);
		data->cheapest = 0;
	}
	else if (nbri == data->b->size - 1
		&& nbri > 1)
		rrb(data, 1);
}

void	ft_rotate_m2(t_data *data)
{
	int	nbri;

	nbri = max_stack(data->b);
	if (data->cheapest <= data->a->size / 2
		&& nbri <= data->b->size / 2
		&& data->cheapest > 0
		&& nbri > 0)
	{
		rr(data);
		data->cheapest--;
	}
	else if (data->cheapest > 0
		&& data->cheapest <= data->a->size / 2)
	{
		ra(data, 1);
		data->cheapest--;
	}
	else if (nbri > 0
		&& nbri <= data->b->size / 2)
		rb(data, 1);
}

void	ft_rotate_m3(t_data *data)
{
	int	nbri;

	nbri = max_stack(data->b);
	if (data->cheapest < data->a->size - 1
		&& nbri < data->b->size - 1
		&& data->cheapest > data->a->size / 2
		&& nbri > data->b->size / 2)
	{
		rrr(data);
		data->cheapest++;
	}
	else if (data->cheapest < data->a->size - 1
		&& data->cheapest > data->a->size / 2)
	{
		rra(data, 1);
		data->cheapest++;
	}
	else if (nbri < data->b->size - 1
		&& nbri > data->b->size / 2)
		rrb(data, 1);
}
