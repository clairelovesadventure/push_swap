/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:10:00 by shutan            #+#    #+#             */
/*   Updated: 2024/02/26 18:10:00 by shutan           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	is_valid_int(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((str[0] != '-' && num > INT_MAX)
			|| (str[0] == '-' && num > ((long)INT_MAX + 1)))
			return (0);
		i++;
	}
	return (1);
}

void	free_split_result(char **result, int count)
{
	int	i;

	if (!result)
		return ;
	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
}

char	**split_string(const char *str, const char *delim, int *count)
{
	char	*s;
	char	*token;
	char	**result;
	int		spaces;

	if (!count || !init_split(str, delim, &s, &result))
		return (NULL);
	spaces = 0;
	token = strtok(s, delim);
	while (token)
	{
		while (*token && *token == ' ')
			token++;
		if (!*token)
			break ;
		result = add_token_to_result(result, token, &spaces);
		if (!result)
			return (handle_split_error(s, result, spaces));
		token = strtok(NULL, delim);
	}
	*count = spaces;
	free(s);
	return (result);
}
