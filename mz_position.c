/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:50:23 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/12 10:37:25 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mz_position(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (stack_b)
	{
		stack_b->pos = i;
		stack_b = stack_b->next;
		i++;
	}
}
