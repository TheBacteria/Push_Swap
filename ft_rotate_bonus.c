/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:28:55 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 20:29:02 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	tmp2 = ft_lstlast(tmp);
	tmp2->next = (*lst);
	(*lst) = tmp;
}
