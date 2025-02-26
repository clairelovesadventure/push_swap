/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:57:10 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 15:34:52 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 获取栈中每个元素的位置 */
void	get_positions(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->head;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

/* 如果没有更大的元素，找到最小的元素作为目标 */
static void	get_smallest_as_target(t_stack *stack_a, int *target_pos)
{
	t_node	*current;
	int		smallest_index;
	int		smallest_pos;

	current = stack_a->head;
	smallest_index = INT_MAX;
	smallest_pos = 0;
	while (current)
	{
		if (current->index < smallest_index)
		{
			smallest_index = current->index;
			smallest_pos = current->position;
		}
		current = current->next;
	}
	*target_pos = smallest_pos;
}

/* 为B中的元素找到对应在A中的目标位置 */
static void	get_target_for_b(t_stack *stack_a, t_node *current_b,
						int *target_index, int *target_pos)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->index > current_b->index
			&& current_a->index < *target_index)
		{
			*target_index = current_a->index;
			*target_pos = current_a->position;
		}
		current_a = current_a->next;
	}
	if (*target_index == INT_MAX)
		get_smallest_as_target(stack_a, target_pos);
}

/* 获取目标位置 */
void	get_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	int		target_index;
	int		target_pos;

	current_b = stack_b->head;
	while (current_b)
	{
		target_index = INT_MAX;
		target_pos = 0;
		get_target_for_b(stack_a, current_b, &target_index, &target_pos);
		current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}

/* 计算将元素从B移到A的代价 */
void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		current_b->cost_b = current_b->position;
		if (current_b->position > size_b / 2)
			current_b->cost_b = -(size_b - current_b->position);
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = -(size_a - current_b->target_pos);
		current_b = current_b->next;
	}
}
