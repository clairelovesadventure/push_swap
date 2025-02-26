/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:57:57 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:16:19 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 旋转栈：将栈顶元素移到栈底 */
static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = first;
	while (last->next)
		last = last->next;
	stack->head = first->next;
	stack->head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/* ra操作：旋转a栈 */
void	ra(t_stack *stack_a, int print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

/* rb操作：旋转b栈 */
void	rb(t_stack *stack_b, int print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

/* rr操作：同时旋转a栈和b栈 */
void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}
