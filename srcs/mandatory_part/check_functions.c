/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:11:24 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/17 06:41:35 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	void_array_control(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->s_a->size)
	{
		if (data->nb[i] == NULL)
			error_print("EMPTY ARRAY DETECTED!");
		i++;
	}
}

void	int_max_and_min_value(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= data->s_a->size)
	{
		tmp = min_and_max_check_atoi(data->nb[i]);
		i++;
	}
}

void	only_1_number(t_data *data)
{
	int	i;

	i = 0;
	while (data->nb[i])
	{
		i++;
	}
	if (i == 1)
		error_print("THERE IS ONLY 1 NUMBER!");
}

void	dublicated_number(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->s_a->size)
	{
		while (j <= data->s_a->size)
		{
			if (ft_atoi(data->nb[i]) == ft_atoi(data->nb[j + 1]))
				error_print("DUBLICATED NUMBER!");
			j++;
		}
		j = 0;
		i++;
	}
}

void	other_than_numbers(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->nb[i])
	{
		while (data->nb[i][j])
		{
			if (!(ft_isdigit(data->nb[i][j])) && data->nb[i][j] != '-'
				&& data->nb[i][j] != '+')
				error_print("CHARACTERS OTHER THAN NUMBERS!");
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_all(t_data *data)
{
	void_array_control(data);
	int_max_and_min_value(data);
	only_1_number(data);
	other_than_numbers(data);
	dublicated_number(data); //HATALI
	add_numbers_to_int(data);
	correct_sorting_check(data->s_a);
}
