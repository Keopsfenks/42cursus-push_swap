/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:08:11 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 07:08:42 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
