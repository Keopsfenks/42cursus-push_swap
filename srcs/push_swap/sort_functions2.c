/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:05:00 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 07:05:20 by segurbuz         ###   ########.fr       */
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
