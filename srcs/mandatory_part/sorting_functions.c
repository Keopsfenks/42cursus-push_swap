/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:49:28 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/17 06:46:56 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int rule)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->s_a->num[0];
	data->s_a->num[0] = data->s_a->num[1];
	data->s_a->num[1] = tmp;
	if (rule == 1)
		ft_printf("sa\n");
}

void	sb(t_data *data, int rule)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data->s_b->num[0];
	data->s_b->num[0] = data->s_b->num[1];
	data->s_b->num[1] = tmp;
	if (rule == 1)
		ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_printf("ss\n");
}

void	pa(t_data *data)
{
	int	tmp;

	tmp = data->s_b->num[0];
	rb(data, 0);
	data->s_b->size--;
	data->s_a->size++;
	rra(data, 0);
	data->s_b->num[0] = tmp;
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	int	tmp;

	tmp = data->s_a->num[0];
	ra(data, 0);
	data->s_a->size--;
	data->s_b->size++;
	if (data->s_b->size > 0)
		rrb(data, 0);
	data->s_b->num[0] = tmp;
	ft_printf("pb\n");
}

void	ra(t_data *data, int rule)
{
	int	i;
	int	tmp;
	int	first_nb;

	i = 0;
	first_nb = data->s_a->num[0];
	while (i <= data->s_a->size)
	{
		tmp = data->s_a->num[i];
		data->s_a->num[i] = data->s_a->num[i + 1];
		data->s_a->num[i + 1] = tmp;
		i++;
	}
	data->s_a->num[data->s_a->size] = first_nb;
	if (rule == 1)
		ft_printf("ra\n");
}

void	rb(t_data *data, int rule)
{
	int	i;
	int	tmp;
	int	first_nb;

	i = 0;
	first_nb = data->s_b->num[0];
	while (i <= data->s_b->size)
	{
		tmp = data->s_b->num[i];
		data->s_b->num[i] = data->s_b->num[i + 1];
		data->s_b->num[i + 1] = tmp;
		i++;
	}
	data->s_b->num[data->s_b->size] = first_nb;
	if (rule == 1)
		ft_printf("ra\n");
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	ft_printf("rr\n");
}

void	rra(t_data *data, int rule)
{
	int	i;
	int	tmp;

	tmp = data->s_a->num[data->s_a->size];
	i = data->s_a->size;
	while (0 < i)
	{
		data->s_a->num[i] = data->s_a->num[i - 1];
		i--;
	}
	data->s_a->num[0] = tmp;
	if (rule == 1)
		ft_printf("rra\n");
}

void	rrb(t_data *data, int rule)
{
	int	i;
	int	tmp;

	tmp = data->s_b->num[data->s_b->size];
	i = data->s_b->size;
	while (0 < i)
	{
		data->s_b->num[i] = data->s_b->num[i - 1];
		i--;
	}
	data->s_b->num[0] = tmp;
	if (rule == 1)
		ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_printf("rrr\n");
}
