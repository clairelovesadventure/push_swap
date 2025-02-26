/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:14:42 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:15:44 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 执行排序操作 */
static void	do_sorting(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	if (!is_sorted(stack_a))
	{
		if (stack_size == 2)
			sa(stack_a, 1);
		else if (stack_size == 3)
			sort_three(stack_a);
		else
			sort_large(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack(&stack_a) || !init_stack(&stack_b))
		exit_error(stack_a, stack_b);
	if (!parse_args(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	do_sorting(stack_a, stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
