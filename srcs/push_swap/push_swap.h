/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:52:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 06:30:06 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libary/ft_libft/libft.h"
# include "stdio.h"

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
	char	**num;
	int		cheapest;
}			t_data;

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
int		min_stack(t_stack *stack);
void	find_cheapest(t_data *data);
int		take_cheapest(t_data *data);
int		find_the_position_number(t_stack *stack, int anum);
void	ft_start(t_data *data);
int		find_number(t_stack *stack, int nbr);
void	ft_rotate_m(t_data *data);
void	ft_rotate_m2(t_data *data);
void	ft_rotate_m3(t_data *data);
void	ft_rotate_o(t_data *data);
void	ft_rotate_o2(t_data *data);
void	ft_rotate_o3(t_data *data);
#endif
