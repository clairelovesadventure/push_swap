/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:19:10 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:27:53 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 获取栈大小 */
int	get_stack_size(t_stack *stack)
{
	return (stack->size);
}

/* 获取最小索引元素的位置 */
int	get_min_index_position(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;

	if (!stack->head)
		return (-1);
	current = stack->head;
	min_index = INT_MAX;
	min_pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = current->position;
		}
		current = current->next;
	}
	return (min_pos);
}

/* 释放栈内存 */
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

/* 获取最大索引元素的位置 */
int	get_max_index_position(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_pos;

	if (!stack->head)
		return (-1);
	current = stack->head;
	max_index = -1;
	max_pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = current->position;
		}
		current = current->next;
	}
	return (max_pos);
}

/* 错误处理 */
void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
