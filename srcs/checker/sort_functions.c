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

void	sa(t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->a->num[0];
	data->a->num[0] = data->a->num[1];
	data->a->num[1] = tmp;
}

void	sb(t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->b->num[0];
	data->b->num[0] = data->b->num[1];
	data->b->num[1] = tmp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

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

void	ra(t_data *data)
{
	int	i;
	int	tmp;
	int	first_nb;

	i = 0;
	first_nb = data->a->num[0];
	while (i < data->a->size)
	{
		tmp = data->a->num[i];
		data->a->num[i] = data->a->num[i + 1];
		data->a->num[i + 1] = tmp;
		i++;
	}
	data->a->num[data->a->size - 1] = first_nb;
}

void	rb(t_data *data)
{
	int	i;
	int	tmp;
	int	first_nb;

	i = 0;
	first_nb = data->b->num[0];
	while (i < data->b->size)
	{
		tmp = data->b->num[i];
		data->b->num[i] = data->b->num[i + 1];
		data->b->num[i + 1] = tmp;
		i++;
	}
	data->b->num[data->b->size - 1] = first_nb;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
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