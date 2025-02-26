/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:20:00 by shutan            #+#    #+#             */
/*   Updated: 2024/02/26 18:20:00 by shutan           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_numbers(char **numbers, int count,
		t_stack *stack_a, int *has_numbers)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (!is_valid_int(numbers[j])
			|| has_duplicate(stack_a, atol(numbers[j])))
		{
			free_split_result(numbers, count);
			return (0);
		}
		add_node_bottom(stack_a, create_node(atol(numbers[j])));
		*has_numbers = 1;
		j++;
	}
	return (1);
}

int	parse_and_fill_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		count;
	char	**numbers;
	int		has_numbers;

	i = 1;
	has_numbers = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (0);
		numbers = split_string(argv[i], " ", &count);
		if (!numbers || count == 0)
			return (0);
		if (!process_numbers(numbers, count, stack_a, &has_numbers))
			return (0);
		free_split_result(numbers, count);
		i++;
	}
	return (has_numbers);
}
