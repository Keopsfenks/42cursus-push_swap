/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:17:16 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/16 21:20:04 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int rule)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->a->num[0];
	data->a->num[0] = data->a->num[1];
	data->a->num[1] = tmp;
	if (rule == 1)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int rule)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->b->num[0];
	data->b->num[0] = data->b->num[1];
	data->b->num[1] = tmp;
	if (rule == 1)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	int	tmp;

	tmp = data->b->num[0];
	rb(data, 0);
	data->b->size--;
	data->a->size++;
	if (data->a->size > 1)
		rra(data, 0);
	data->a->num[0] = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	int	tmp;

	tmp = data->a->num[0];
	ra(data, 0);
	data->a->size--;
	data->b->size++;
	if (data->b->size > 1)
		rrb(data, 0);
	data->b->num[0] = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_data *data, int rule)
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
	if (rule == 1)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int rule)
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
	if (rule == 1)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	write(1, "rr\n", 3);
}

void	rra(t_data *data, int rule)
{
	int	i;
	int	tmp;

	tmp = data->a->num[data->a->size - 1];
	i = data->a->size;
	while (0 < i)
	{
		data->a->num[i] = data->a->num[i - 1];
		i--;
	}
	data->a->num[0] = tmp;
	if (rule == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int rule)
{
	int	i;
	int	tmp;

	tmp = data->b->num[data->b->size - 1];
	i = data->b->size;
	while (0 < i)
	{
		data->b->num[i] = data->b->num[i - 1];
		i--;
	}
	data->b->num[0] = tmp;
	if (rule == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}