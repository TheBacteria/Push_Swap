/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:29:43 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/21 16:21:37 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mz_error2(t_list **stack)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack);
	exit(1);
}

static int	str_to_int(const char *str, int *i, int sign, t_list **stack)
{
	unsigned long long	nb;
	int					count;

	nb = 0;
	count = 0;
	while (str[*i] == '0')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb * 10 + str[*i] - '0';
		(*i)++;
		count++;
		if ((sign == 1 && nb > 2147483647) || (sign == -1 && nb > 2147483648))
			mz_error2(stack);
	}
	if (count > 10 || (str[*i] != 32 && str[*i] != '\0'))
		mz_error2(stack);
	while (str[*i] && str[*i] == 32)
		(*i)++;
	return ((int)nb * sign);
}

int	ft_atoi(const char *str, int *i, t_list **stack)
{
	int	sign;
	int	tmp;

	sign = 1;
	while (str[*i] && str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		tmp = *i;
		if (str[tmp + 1] < '0' || str[tmp + 1] > '9')
			mz_error2(stack);
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (str_to_int(str, i, sign, stack));
}
