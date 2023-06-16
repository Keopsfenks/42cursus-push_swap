/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:52:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/16 19:55:15 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac > 1)
	{
		ft_parse(data, ac, av); //leak var
		if (data->a->size < 6)
			five_sort(data);
		else
			ft_sort(data);
	}
	else
		return (0);
}