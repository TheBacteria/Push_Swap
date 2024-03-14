/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:28:55 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:44:55 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst, int i)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst)->next;
	(*lst)->next = NULL;
	tmp2 = ft_lstlast(tmp);
	tmp2->next = (*lst);
	(*lst) = tmp;
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
}
