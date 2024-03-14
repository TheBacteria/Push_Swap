/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:18 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 11:54:10 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mz_sort_3(t_list **lst)
{
	if (ft_lstsize(*lst) == 2 && mz_is_sorted(*lst) == 1)
		ft_swap(lst, 1);
	while (mz_is_sorted(*lst) == 1)
	{
		if ((*lst)->content < (*lst)->next->content
			&& (*lst)->next->content > (*lst)->next->next->content)
			ft_reverse_rotate(lst, 1);
		else if ((*lst)->content > (*lst)->next->content
			&& (*lst)->content < (*lst)->next->next->content)
			ft_swap(lst, 1);
		else if ((*lst)->content > (*lst)->next->content
			&& (*lst)->content > (*lst)->next->next->content)
			ft_rotate(lst, 1);
	}
}
