/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:03:50 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/17 07:36:22 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libary/ft_printf/ft_printf.h"
# include "../libary/ft_libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*num;
	int	size;
	int	maxi;
	int	mini;
}	t_stack;

typedef struct s_data
{
	t_stack	*s_a;
	t_stack	*s_b;
	char	**nb;
	int		*steps;
}	t_data;

//FUNCTION NAMES
char	*copy(char *s1, char *s2);
char	*copy_next(char *dst, char *src);
void	check_all(t_data *data);
void	error_print(char *str);
void	add_numbers_to_int(t_data *data);
int		min_and_max_check_atoi(const char *str);
void	sa(t_data *data, int rule);
void	sb(t_data *data, int rule);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data, int rule);
void	rb(t_data *data, int rule);
void	rr(t_data *data);
void	rra(t_data *data, int rule);
void	rrb(t_data *data, int rule);
void	rrr(t_data *data);
int		correct_sorting_check(t_stack *stack);
void	choose_sort(t_data *data);
void	calculate_steps(t_data *data);


#endif