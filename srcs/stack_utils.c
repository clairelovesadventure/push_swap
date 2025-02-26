/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:58:10 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:23:36 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 创建新节点 */
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->position = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/* 将节点添加到栈底 */
void	add_node_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack->head)
	{
		stack->head = new_node;
	}
	else
	{
		last = stack->head;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	stack->size++;
}

/* 将节点添加到栈顶 */
void	add_node_top(t_stack *stack, t_node *new_node)
{
	if (!stack->head)
	{
		stack->head = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

/* 从栈顶弹出节点 */
t_node	*pop_node_top(t_stack *stack)
{
	t_node	*top;

	if (!stack->head)
		return (NULL);
	top = stack->head;
	if (top->next)
	{
		stack->head = top->next;
		stack->head->prev = NULL;
		top->next = NULL;
	}
	else
		stack->head = NULL;
	stack->size--;
	return (top);
}

/* 检查栈是否已排序 */
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->head || !stack->head->next)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
