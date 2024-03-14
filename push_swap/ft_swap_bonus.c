/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:13:49 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 20:33:32 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) < 2)
		return ;
	if ((*lst)->next == NULL)
		return ;
	tmp = (*lst)->next->next;
	(*lst)->next->next = *lst;
	(*lst) = (*lst)->next;
	(*lst)->next->next = tmp;
}
