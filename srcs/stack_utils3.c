/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shutan <shutan@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:19:30 by shutan            #+#    #+#             */
/*   Updated: 2025/02/26 11:27:49 by shutan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 检查字符串是否为有效数字 */
int	is_number(char *str)
{
	int	i;
	int	is_digit_found;

	i = 0;
	is_digit_found = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			is_digit_found = 1;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (is_digit_found);
}

/* 检查溢出 */
static long	check_overflow(long result, char digit, int sign)
{
	if (result > LONG_MAX / 10
		|| (result == LONG_MAX / 10 && digit - '0' > LONG_MAX % 10))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (result * 10 + (digit - '0'));
}

/* 将字符串转换为长整型 */
long	atol(const char *str)
{
	long	result;
	int		sign;
	int		i;
	long	temp;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = check_overflow(result, str[i], sign);
		if (temp == LONG_MAX || temp == LONG_MIN)
			return (temp);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* 整数绝对值函数 */
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
