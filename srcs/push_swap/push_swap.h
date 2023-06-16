/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:52:09 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/16 21:59:14 by segurbuz         ###   ########.fr       */
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
int		is_sorted(t_data *data);
void	ft_sort(t_data *data);
void	maxb(t_data *data);
void	minb(t_data *data);




#endif
