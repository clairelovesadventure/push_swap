/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:07:05 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 18:19:59 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* 节点结构体 */
typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* 栈结构体 */
typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/* 栈初始化函数 */
int		init_stack(t_stack **stack);
int		parse_args(int argc, char **argv, t_stack *stack_a);
void	assign_index(t_stack *stack_a, int stack_size);

/* 栈操作函数 */
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);
void	reverse_rotate(t_stack *stack);

/* 栈工具函数 */
t_node	*create_node(int value);
void	add_node_bottom(t_stack *stack, t_node *new_node);
void	add_node_top(t_stack *stack, t_node *new_node);
t_node	*pop_node_top(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		get_min_index_position(t_stack *stack);
int		get_max_index_position(t_stack *stack);
int		abs(int n);

/* 排序算法函数 */
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/* 代价计算函数 */
void	get_target_position(t_stack *stack_a, t_stack *stack_b);
void	calculate_cost(t_stack *stack_a, t_stack *stack_b);
void	execute_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void	get_positions(t_stack *stack);

/* 错误处理 */
void	exit_error(t_stack *stack_a, t_stack *stack_b);
int		is_number(char *str);
int		has_duplicate(t_stack *stack, int num);

/* 辅助函数 */
long	atol(const char *str);

int		is_valid_int(const char *str);
void	free_split_result(char **result, int count);
char	**split_string(const char *str, const char *delim, int *count);

/* 添加新函数声明 */
int		parse_and_fill_stack(int argc, char **argv, t_stack *stack_a);
char	**handle_split_error(char *s, char **result, int spaces);
char	**add_token_to_result(char **result, char *token, int *spaces);
int		init_split(const char *str, const char *delim,
			char **s, char ***result);

#endif 