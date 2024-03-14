/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:04:11 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 17:42:01 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (!stack_1 || !stack_2)
		return ;
	if ((*stack_1) == NULL)
		return ;
	tmp = (*stack_1)->next;
	(*stack_1)->next = (*stack_2);
	(*stack_2) = (*stack_1);
	(*stack_1) = tmp;
}
