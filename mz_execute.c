/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:11:27 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:47:02 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mz_cost_calculator(t_list *lst, int *first)
{
	int	a;
	int	b;

	a = lst->cost_a;
	b = lst->cost_b;
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	*first = a + b;
}

t_list	*mz_cheap(t_list *stack_b)
{
	t_list	*tmp;
	int		first;
	int		second;

	mz_cost_calculator(stack_b, &second);
	tmp = stack_b;
	while (stack_b)
	{
		mz_cost_calculator(stack_b, &first);
		if (first < second)
		{
			tmp = stack_b;
			second = first;
		}
		stack_b = stack_b->next;
	}
	return (tmp);
}

static void	full_rotate(t_list *cheap, t_list **stack_a, t_list **stack_b)
{
	while (cheap->cost_a > 0 && cheap->cost_b > 0)
	{
		cheap->cost_a = cheap->cost_a - 1;
		cheap->cost_b = cheap->cost_b - 1;
		ft_rr(stack_a, stack_b);
	}
	while (cheap->cost_a < 0 && cheap->cost_b < 0)
	{
		cheap->cost_a = cheap->cost_a + 1;
		cheap->cost_b = cheap->cost_b + 1;
		ft_rrr(stack_a, stack_b);
	}
}

static void	simple_rotate(t_list *cheap, t_list **stack_a, t_list **stack_b)
{
	while (cheap->cost_a != 0 || cheap->cost_b != 0)
	{
		if (cheap->cost_a > 0)
		{
			cheap->cost_a = cheap->cost_a - 1;
			ft_rotate(stack_a, 1);
		}
		else if (cheap->cost_a < 0)
		{
			cheap->cost_a = cheap->cost_a + 1;
			ft_reverse_rotate(stack_a, 1);
		}
		else if (cheap->cost_b > 0)
		{
			cheap->cost_b = cheap->cost_b - 1;
			ft_rotate(stack_b, 2);
		}
		else if (cheap->cost_b < 0)
		{
			cheap->cost_b = cheap->cost_b + 1;
			ft_reverse_rotate(stack_b, 2);
		}
	}
}

void	mz_execute(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheap;

	cheap = mz_cheap(*stack_b);
	full_rotate(cheap, stack_a, stack_b);
	simple_rotate(cheap, stack_a, stack_b);
	ft_push(stack_b, stack_a, 1);
}
