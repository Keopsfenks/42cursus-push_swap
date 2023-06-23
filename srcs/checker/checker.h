/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 05:38:28 by segurbuz          #+#    #+#             */
/*   Updated: 2023/06/23 06:39:16 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libary/ft_get_next_line/get_next_line.h"
# include "../libary/ft_libft/libft.h"

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
	char	**num;
}			t_data;

char	*ps_strjoin(char *s1, char *s2);
int		ps_atoi(const char *str);
void	error(void);
void	ft_parse(t_data *data, int ac, char **av);
int		is_sorted(t_stack *stack);
void	ft_exit_free_all(t_data *data, char c);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);


#endif
