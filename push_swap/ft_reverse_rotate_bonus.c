/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:44:10 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 20:29:40 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_list	*mz_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = mz_before_last(*lst);
	tmp2 = ft_lstlast(*lst);
	tmp2->next = (*lst);
	(*lst) = tmp2;
	tmp->next = NULL;
}
