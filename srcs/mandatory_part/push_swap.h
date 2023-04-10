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
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				content_2;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	int 	pivot;

}	t_data;

//FUNCTION NAMES
void	quick_short(t_data *data, char *nb);

#endif
