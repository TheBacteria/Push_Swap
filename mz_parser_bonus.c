/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:59 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 16:33:44 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	mz_error(t_list **stack, t_list *new)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack);
	free(new);
	exit(1);
}

static int	mz_is_duplicate(t_list *lst, int number)
{
	while (lst)
	{
		if (lst->content == number)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

static int	mz_sign(char **s, int j, int *i)
{
	++*i;
	if (s[j][*i - 1] == '-')
		return (-1);
	else
		return (1);
}

static int	mz_checker(char **s)
{
	int					i;
	int					j;
	unsigned long long	nb;
	int					sign;

	j = 1;
	sign = 1;
	while (s[j])
	{
		i = 0;
		nb = 0;
		while (s[j][i] && s[j][i] == 32)
			i++;
		if (s[j][i] == '-' || s[j][i] == '+')
			sign = mz_sign(s, j, &i);
		if (s[j][i] == '\0' || !(s[j][i] >= '0' && s[j][i] <= '9'))
			return (-1);
		while (s[j][i] && (s[j][i] >= '0' && s[j][i] <= '9'))
			nb = nb * 10 + s[j][i++] - '0';
		if ((sign == 1 && nb > 2147483647) || (sign == -1 && nb > 2147483648))
			return (-1);
		j++;
	}
	return (0);
}

t_list	*mz_parser(char **s)
{
	t_list	*stack;
	t_list	*new;
	int		i;
	int		j;
	int		nb;

	i = 1;
	j = 0;
	stack = NULL;
	if (mz_checker(s) == -1)
		return (write(2, "Error\n", 6), NULL);
	while (s[i])
	{
		nb = ft_atoi(s[i], &j, &stack);
		new = ft_lstnew(nb);
		if (!new || mz_is_duplicate(stack, nb))
			mz_error(&stack, new);
		ft_lstadd_back(&stack, new);
		if (s[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
	return (stack);
}
