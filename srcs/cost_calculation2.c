/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:18:30 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 15:33:03 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 处理剩余的单独旋转 */
void	do_remaining_rotations(t_stack *stack, int *cost, char stack_name)
{
	while (*cost > 0)
	{
		if (stack_name == 'a')
			ra(stack, 1);
		else if (stack_name == 'b')
			rb(stack, 1);
		(*cost)--;
	}
	while (*cost < 0)
	{
		if (stack_name == 'a')
			rra(stack, 1);
		else if (stack_name == 'b')
			rrb(stack, 1);
		(*cost)++;
	}
}

/* 查找代价最小的节点 */
t_node	*find_cheapest_node(t_stack *stack_b)
{
	t_node	*current;
	int		cheapest_total_cost;
	t_node	*cheapest_node;

	current = stack_b->head;
	cheapest_total_cost = INT_MAX;
	cheapest_node = NULL;
	while (current)
	{
		if (abs(current->cost_a) + abs(current->cost_b) < cheapest_total_cost)
		{
			cheapest_total_cost = abs(current->cost_a) + abs(current->cost_b);
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

/* 同时旋转两个栈以节省操作 */
void	do_combined_rotations(t_stack *stack_a, t_stack *stack_b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/* 执行成本最低的移动 */
void	execute_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest_cost_a;
	int		cheapest_cost_b;
	t_node	*cheapest_node;

	cheapest_node = find_cheapest_node(stack_b);
	if (cheapest_node)
	{
		cheapest_cost_a = cheapest_node->cost_a;
		cheapest_cost_b = cheapest_node->cost_b;
		do_combined_rotations(stack_a, stack_b,
			&cheapest_cost_a, &cheapest_cost_b);
		do_remaining_rotations(stack_a, &cheapest_cost_a, 'a');
		do_remaining_rotations(stack_b, &cheapest_cost_b, 'b');
		pa(stack_a, stack_b, 1);
	}
}
