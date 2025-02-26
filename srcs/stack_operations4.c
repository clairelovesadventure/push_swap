/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:17:30 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:20:00 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pb操作：将a栈顶元素移动到b栈顶 */
void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*top_a;

	if (stack_a->size == 0)
		return ;
	top_a = pop_node_top(stack_a);
	add_node_top(stack_b, top_a);
	if (print)
		write(1, "pb\n", 3);
}
