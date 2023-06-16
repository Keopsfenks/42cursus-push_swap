/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:50:13 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/16 21:50:26 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_steps(t_data *data)
{
	int	i;
	int	nbr_i;

	i = -1;

	while (++i < data->a->size)
	{

	}
}
static void	find_cheapest(t_data *data)
{
	maxb(data);
	minb(data);
	calculate_steps(data);
}

void	ft_sort(t_data *data)
{
	data->steps = malloc(sizeof(int) * data->a->size);
	pb(data);
	pb(data);
	while (0 < data->a->size)
	{
		find_cheapest(data);
	}
}