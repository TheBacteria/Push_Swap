/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:37:14 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 12:01:46 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	mz_search(t_list *lst, int i)
{
	while (lst)
	{
		if (lst->index <= i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	mz_push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		mid;
	int		i;

	mid = ft_lstsize(*stack_a) / 2;
	i = 0;
	while (mz_search(*stack_a, mid) == 0)
	{
		if ((*stack_a)->index <= mid)
			ft_push(stack_a, stack_b, 2);
		else
			ft_rotate(stack_a, 1);
		i++;
	}
	while (ft_lstsize(*stack_a) > 3)
		ft_push(stack_a, stack_b, 2);
	mz_sort_3(stack_a);
}

static	void	mz_last_step(t_list **stack_a)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = *stack_a;
	while (lst)
	{
		if (lst->index == 1)
			break ;
		lst = lst->next;
		i++;
	}
	while (mz_is_sorted(*stack_a) == 1)
	{
		if (ft_lstsize(*stack_a) / 2 >= i)
			ft_rotate(stack_a, 1);
		else
			ft_reverse_rotate(stack_a, 1);
	}
}

void	mz_sort(t_list **stack_a, t_list **stack_b)
{
	if (mz_is_sorted(*stack_a) == 0 && ft_lstsize(*stack_b) == 0)
		return ;
	mz_push_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		mz_position(*stack_a, *stack_b);
		mz_target(*stack_a, *stack_b);
		mz_cost(*stack_a, *stack_b);
		mz_execute(stack_a, stack_b);
	}
	if (mz_is_sorted(*stack_a) == 1)
		mz_last_step(stack_a);
}
