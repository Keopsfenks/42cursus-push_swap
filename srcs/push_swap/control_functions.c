/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:59:20 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/20 04:58:36 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**add_numbersto_int(t_data *data, int ac, char **av)
{
	char	*str;
	char	**split;
	int		i;

	i = 1;
	data->a = ft_calloc(sizeof(t_stack), 1);
	data->b = ft_calloc(sizeof(t_stack), 1);
	str = ft_strdup("");
	while (i < ac)
	{
		str = ps_strjoin(str, av[i]);
		str = ps_strjoin(str, " ");
		i++;
	}
	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
		i++;
	data->a->size = i;
	data->b->size = 0;
	data->a->num = malloc(sizeof(int) * data->a->size);
	data->b->num = malloc(sizeof(int) * data->a->size);
	return (split);
}

void	other_than_numbers(char **num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (num[i])
	{
		while (num[i][j])
		{
			if (!(ft_isdigit(num[i][j])) && num[i][j] != '-'
				&& num[i][j] != '+')
				error();
			j++;
		}
		j = 0;
		i++;
	}
}

int	is_duplicated(t_data *data, char **num)
{
	int	i;
	int	index;
	int	count;

	i = 0;
	while (i < data->a->size)
	{
		index = 0;
		count = 0;
		while (index < data->a->size)
		{
			if (ps_atoi(num[i]) == ps_atoi(num[index]))
				count++;
			index++;
		}
		if (count > 1)
			error();
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < stack->size - 1)
	{
		if (stack->num[i] > stack->num[i + 1])
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

void	ft_parse(t_data *data, int ac, char **av)
{
	char	**num;
	int		i;

	i = -1;
	num = add_numbersto_int(data, ac, av);
	other_than_numbers(num);
	is_duplicated(data, num);
	while (++i < data->a->size)
		data->a->num[i] = ps_atoi(num[i]);
	if (is_sorted(data->a))
		exit(1);
}

