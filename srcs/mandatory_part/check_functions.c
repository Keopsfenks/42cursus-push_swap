#include "push_swap.h"

int	min_and_max_control(t_data *data)
{
	int		i;
	long	num;

	i = 0;
	while (data->numbers[i])
	{
		num = ft_long_atoi(data->numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	void_array_control(t_data *data)
{

	if (data->numbers[0] == NULL)
		return (0);
	return (1);
}

void	check_all(t_data *data)
{
	if (void_array_control(data) == 0)
		error_print("NO NUMBER FOUND.");
	else if (min_and_max_control(data) == 0)
		error_print("TAKES A MAXIMUM OR MINIMUM VALUE.");
}