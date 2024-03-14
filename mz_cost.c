/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:14:21 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:46:39 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	mz_cost_b(t_list *stack_b)
{
	t_list	*lst;

	lst = stack_b;
	while (lst)
	{
		if (lst->pos <= (ft_lstsize(stack_b) / 2))
			lst->cost_b = lst->pos;
		else
			lst->cost_b = (ft_lstsize(stack_b) - lst->pos) * -1;
		lst = lst->next;
	}
}

static	int	mz_biggest_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content > stack_b->content)
			return (0);
		tmp = tmp->next;
	}
	tmp = stack_a;
	tmp2 = stack_a;
	while (tmp)
	{
		if (tmp->content < tmp2->content)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp2->pos <= (ft_lstsize(stack_a) / 2))
		stack_b->cost_a = tmp2->pos;
	else
		stack_b->cost_a = (ft_lstsize(stack_a) - tmp2->pos) * -1;
	return (1);
}

static	void	mz_cost_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*lst;

	while (stack_b)
	{
		lst = stack_a;
		while (lst && mz_biggest_cost(stack_a, stack_b) == 0)
		{
			if (lst->pos == stack_b->target_pos)
			{
				if (lst->pos <= (ft_lstsize(stack_a) / 2))
					stack_b->cost_a = lst->pos;
				else
					stack_b->cost_a = (ft_lstsize(stack_a) - lst->pos) * -1;
				break ;
			}
			lst = lst->next;
		}
		stack_b = stack_b->next;
	}
}

void	mz_cost(t_list *stack_a, t_list *stack_b)
{
	mz_cost_b(stack_b);
	mz_cost_a(stack_a, stack_b);
}
