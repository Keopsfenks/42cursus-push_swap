#include "push_swap.h"

void	sa(t_data *data, int flag)
{
	int	tmp;

	tmp = data->stack_a->content;
	data->stack_a->content = data->stack_a->next->content;
	data->stack_a->next->content = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	return;
}

void	sb(t_data *data, int flag)
{
	int	tmp;

	tmp = data->stack_b->content;
	data->stack_b->content = data->stack_b->next->content;
	data->stack_b->next->content = tmp;
	if (flag == 1)
		ft_printf("sb\n");
	return;
}

void	ss(t_data *data, int flag)
{
	sa(data, 0);
	sb(data, 0);
	if (flag == 1)
		ft_printf("ss\n");
}

void	pb(t_data *data, int flag)
{
	int	tmp;

	if(data->stack_a == NULL)
		error_print("STACK A VALUE = NULL");
	tmp = ft_lstlast(data->stack_a);
	ft_lstlast_index(data->stack_b, tmp);
	if (flag == 1)
		ft_printf("pb\n");
}

void	pa(t_data *data, int flag)
{
	int	tmp;

	if(data->stack_b == NULL)
		error_print("STACK B VALUE = NULL");
	tmp = ft_lstlast(data->stack_b);
	ft_lstlast_index(data->stack_a, tmp);
	if (flag == 1)
		ft_printf("pa\n");
}

void	ra(t_data *data, int flag)
{
	int	tmp;

	tmp = data->stack_a->content;
	ft_lst_rotate(data->stack_a, tmp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_data *data, int flag)
{
	int	tmp;

	tmp = data->stack_b->content;
	ft_lst_rotate(data->stack_b, tmp);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_data *data, int flag)
{
	ra(data, 0);
	rb(data, 0);
	if (flag == 1)
		ft_printf("rr\n");
}

void	rra(t_data *data, int flag)
{
	int	tmp;
	int last_tmp;

	last_tmp = ft_lstlast(data->stack_a);
	tmp = ft_lstlast(data->stack_a);
	while(data->stack_a->content != last_tmp)
		ft_lst_rotate_reverse(data->stack_a, tmp);
	if (flag == 1)
		ft_printf("rra\n");
}
void	rrb(t_data *data, int flag)
{
	int	tmp;
	int last_tmp;

	last_tmp = ft_lstlast(data->stack_b);
	tmp = ft_lstlast(data->stack_b);
	while(data->stack_b->content != last_tmp)
		ft_lst_rotate_reverse(data->stack_b, tmp);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_data *data, int flag)
{
	rra(data, 0);
	rrb(data, 0);
	if (flag == 1)
		ft_printf("rrr\n");
}