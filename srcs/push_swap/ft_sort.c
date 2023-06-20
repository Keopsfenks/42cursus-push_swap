/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:50:13 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/20 03:44:45 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_steps(t_sort *calc)
{
	int	i;

	i = 0;
	while (calc->a > 0 && calc->b > 0)
	{
		calc->a--;
		calc->b--;
		i++;
	}
	while (calc->ar > 0 && calc->br > 0)
	{
		calc->ar--;
		calc->br--;
		i++;
	}
	while (calc->a-- > 0)
		i++;
	while (calc->ar-- > 0)
		i++;
	while (calc->b-- > 0)
		i++;
	while (calc->br-- > 0)
		i++;
	return (i);
}

void	find_cheapest(t_data *data, t_sort *calc)
{
	int	i;

	i = -1;
	while (++i < data->a->size)
	{
		stack_moves_a(data, calc, i);
		stack_moves_b(data, calc, find_the_spot(data->b, data->a->num[i]));
		data->steps[i] += calculate_steps(calc) + 1;
	}
	take_cheapest(data);
}

void	make_the_opt_moves(t_data *data, t_sort *sort)
{
	while (sort->a > 0 && sort->b > 0)
	{
		rr(data);
		sort->a--;
		sort->b--;
	}
	while (sort->ar > 0 && sort->br > 0)
	{
		rrr(data);
		sort->ar--;
		sort->br--;
	}
	while (sort->a-- > 0)
		ra(data, 1);
	while (sort->ar-- > 0)
		rra(data, 1);
	while (sort->b-- > 0)
		rb(data, 1);
	while (sort->br-- > 0)
		rrb(data, 1);
}


void	send_the_cheapest(t_data *data)
{
	t_sort	sort;

	moves_init(&sort);
	send_the_a(data, &sort);
	send_the_b(data, &sort);
	make_the_opt_moves(data, &sort);
	pb(data);
}

void	send_the_a(t_data *data, t_sort *sort)
{
	int	i;

	i = stack_moves_i(data->a, find_the_spot(data->a, data->a->num[data->cheapest]));
	while (i != 0)
	{
		stack_moves_a_2(data, sort, find_the_spot(data->a, data->a->num[data->cheapest]));
		i--;
	}
}

void	send_the_b(t_data *data, t_sort *sort)
{
	int	i;

	i = stack_moves_i(data->b,find_the_spot(data->b,data->a->num[data->cheapest]));
	while (i != 0)
	{
		stack_moves_b_2(data, sort, find_the_spot(data->b, data->a->num[data->cheapest]));
		i--;
	}
}

void	correct_sorting_stackb(t_data *data)
{
	while (data->b->size != 0)
	{
		if (max_stack(data->b) == 0)
			pa(data);
		else if (max_stack(data->b) <= data->b->size / 2)
			rb(data, 1);
		else if (max_stack(data->b) > data->b->size / 2)
			rrb(data, 1);
	}
}

void	ft_sort(t_data *data)
{
	t_sort	calc;

	moves_init(&calc);
	data->steps = malloc(sizeof(int) * data->a->size);
	pb(data);
	pb(data);
	while (0 < data->a->size)
	{
		find_cheapest(data, &calc);
		send_the_cheapest(data);
	}
	//correct_sorting_stackb(data);
}
