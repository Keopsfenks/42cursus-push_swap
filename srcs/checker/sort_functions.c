/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:17:16 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 06:46:50 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_data *data)
{
	int	tmp;

	tmp = data->b->num[0];
	rb(data);
	data->b->size--;
	data->a->size++;
	if (data->a->size > 1)
		rra(data);
	data->a->num[0] = tmp;
}

void	pb(t_data *data)
{
	int	tmp;

	tmp = data->a->num[0];
	ra(data);
	data->a->size--;
	data->b->size++;
	if (data->b->size > 1)
		rrb(data);
	data->b->num[0] = tmp;
}

void	rra(t_data *data)
{
	int	i;
	int	tmp;

	tmp = data->a->num[data->a->size - 1];
	i = data->a->size - 1;
	while (0 < i)
	{
		data->a->num[i] = data->a->num[i - 1];
		i--;
	}
	data->a->num[0] = tmp;
}

void	rrb(t_data *data)
{
	int	i;
	int	tmp;

	tmp = data->b->num[data->b->size - 1];
	i = data->b->size - 1;
	while (0 < i)
	{
		data->b->num[i] = data->b->num[i - 1];
		i--;
	}
	data->b->num[0] = tmp;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
