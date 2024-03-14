/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:44:10 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:44:32 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*mz_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_reverse_rotate(t_list **lst, int i)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = mz_before_last(*lst);
	tmp2 = ft_lstlast(*lst);
	tmp2->next = (*lst);
	(*lst) = tmp2;
	tmp->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
}
