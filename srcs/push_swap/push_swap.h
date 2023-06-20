/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:52:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/20 04:07:22 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libary/ft_libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	*num;
	int	size;
	int	maxi;
	int	mini;
}		t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		*steps;
	int		cheapest;
}			t_data;

typedef	struct s_sort
{
	int	a;
	int	ar;
	int	b;
	int	br;
}		t_sort;


void	ft_parse(t_data *data, int ac, char **av);
char	*ps_strjoin(char *s1, char *s2);
int		ps_atoi(const char *str);
void	error(void);
void	five_sort(t_data *data);
void	sa(t_data *data, int rule);
void	sb(t_data *data, int rule);
void	ss(t_data *data);
void	ra(t_data *data, int rule);
void	rb(t_data *data, int rule);
void	rr(t_data *data);
void	rra(t_data *data, int rule);
void	rrb(t_data *data, int rule);
void	rrr(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
int		is_sorted(t_stack *stack);
void	ft_sort(t_data *data);
int		max_stack(t_stack *stack);
int		min_stack(t_stack *stack);
int		ft_find_place_b(t_data *data, int i);
int		find_the_spot(t_stack *stack, int a);
void	stack_moves_a(t_data *data, t_sort *calc, int i);
void	stack_moves_b(t_data *data, t_sort *calc, int i);
void	moves_init(t_sort *calc);
int		take_cheapest(t_data *data);
int		stack_moves_i(t_stack *stack, int i);
void	send_the_a(t_data *data, t_sort *sort);
void	send_the_b(t_data *data, t_sort *sort);
void	stack_moves_a_2(t_data *data, t_sort *calc, int i);
void	stack_moves_b_2(t_data *data, t_sort *calc, int i);



#endif
