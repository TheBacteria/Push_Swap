/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:13:49 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:45:51 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, int i)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if ((*lst)->next == NULL)
		return ;
	tmp = (*lst)->next->next;
	(*lst)->next->next = *lst;
	(*lst) = (*lst)->next;
	(*lst)->next->next = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
}
