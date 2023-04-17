/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42istanb>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:08:26 by segurbuz          #+#    #+#             */
/*   Updated: 2023/04/16 21:30:03 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

char	*copy_next(char *dst, char *src)
{
	size_t	i;

	i = -1;
	if ((ft_strlen(src) + 1) != 0)
	{
		while (src[++i] && i < ((ft_strlen(src) + 1) - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (dst);
}

char	*copy(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	copy_next(ptr + i, s2);
	free (s1);
	return (ptr);
}

int	min_and_max_check_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48) * sign;
		if (result > 2147483647 || result < -2147483648)
			error_print("TAKES A MAXIMUM OR MINIMUM VALUE!");
		i++;
	}
	return ((int)result);
}

int	correct_sorting_check(t_stack *stack)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= stack->size)
	{
		if (stack->num[i] > stack->num[i + 1])
			return (1);
		i++;
	}
	error_print("SORTED CORRECTLY!");
	return (0);
}
