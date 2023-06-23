/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:50:13 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/22 23:03:03 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_sort(t_data *data)
{
	ft_rotate_m(data);
	ft_rotate_m2(data);
	ft_rotate_m3(data);
}

void	ft_sort(t_data *data)
{
	ft_rotate_o(data);
	ft_rotate_o2(data);
	ft_rotate_o3(data);
}

void	ft_start(t_data *data)
{
	if (data->a->num[data->cheapest] < data->b->num[min_stack(data->b)])
	{
		while (1)
		{
			if (data->cheapest == 0 && min_stack(data->b) == 0)
				break ;
			ft_min_sort(data);
		}
		pb(data);
		sb(data, 1);
	}
	else
	{
		while (1)
		{
			if (data->cheapest == 0
				&& find_the_position_number(data->b, \
				data->a->num[data->cheapest]) == 0)
				break ;
			ft_sort(data);
		}
		pb(data);
	}
}
