/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:48:39 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/09 21:48:41 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fsort(t_data *data)
{
	int	i;

	i = 0;
	data->steps = ft_calloc(sizeof(int), data->s_a->size);
	pb(data);
	pb(data);
	while (i <= data->s_a->size)
	{
		calculate_steps(data);
		i++;
	}
}

void	choose_sort(t_data *data)
{
	fsort(data);
}