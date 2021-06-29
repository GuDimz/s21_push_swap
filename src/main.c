/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:48:53 by agigi             #+#    #+#             */
/*   Updated: 2021/06/29 18:38:04 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

static void	ft_init(t_data *data, int argc, char **argv)
{
	int		i;
	t_cell	*cell;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		cell = ft_calloc(1, sizeof(t_cell));
		if (!cell)
			ft_error_exit("Error\n");
		cell->value = ft_atoi(argv[i]);
		new = ft_lstnew(cell);
		if (!new)
			ft_error_exit("Error\n");
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
}

int	ft_check_sort_stack_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp->content)
	{
		if (((t_cell *)tmp->content)->order < ((t_cell *)tmp->next->content)->order)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ft_check_input(argc, argv) == -1)
		ft_error_exit("Error\n");
	if (!ft_check_input(argc, argv))
		return (0);
	ft_init(&data, argc, argv);
	ft_add_order(&data);
	if (ft_lstsize(data.stack_a) > 5)
	{
		ft_big_sort_stack(&data);
		if (!ft_check_sort_stack_a(&data))
			ft_sort_half_a(&data);
	}
	// else
	// 	ft_small_sort_stack(&data);
	return (0);
}

/*
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
*/
