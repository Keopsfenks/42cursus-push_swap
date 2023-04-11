/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:20:49 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/04 13:35:36 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libary/ft_printf/ft_printf.h"
# include "../libary/ft_libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int 			index;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**numbers;
	int		size;
	int 	pivot;

}	t_data;

//FUNCTION NAMES
void		quick_short(t_data *data, char *nb);
void		error_print(char *str);
int			ft_lstsize(t_list *stack);
int 		ft_lstlast(t_list *stack);
void		sa(t_data *data, int flag);
void		sb(t_data *data, int flag);
void		ss(t_data *data, int flag);
void		pb(t_data *data, int flag);
void		pa(t_data *data, int flag);
void		ra(t_data *data, int flag);
void		rb(t_data *data, int flag);
void		rr(t_data *data, int flag);
void		rra(t_data *data, int flag);
void		rrb(t_data *data, int flag);
void		rrr(t_data *data, int flag);
void		ft_lstlast_index(t_list *stack, int value);
void		ft_lst_rotate(t_list *stack, int value);
void		ft_lst_rotate_reverse(t_list *stack, int value);
void 		check_all(t_data *data);
long int	ft_long_atoi(const char *str);

#endif
