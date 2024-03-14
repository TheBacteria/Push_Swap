/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:30:22 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:49:32 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mz_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	t_list	*max;
	t_list	*tmp2;

	while (stack_b)
	{
		tmp = stack_a;
		max = stack_a;
		while (tmp)
		{
			if (tmp->content > stack_b->content)
			{
				tmp2 = max;
				max = tmp;
				if (tmp->content > tmp2->content
					&& tmp2->content > stack_b->content)
					max = tmp2;
			}
			tmp = tmp->next;
		}
		stack_b->target_pos = max->pos;
		stack_b = stack_b->next;
	}
}
