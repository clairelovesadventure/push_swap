/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:12:30 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:19:12 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 反向旋转栈：将栈底元素移到栈顶 */
void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}

/* rra操作：反向旋转a栈 */
void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

/* rrb操作：反向旋转b栈 */
void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

/* rrr操作：同时反向旋转a栈和b栈 */
void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
