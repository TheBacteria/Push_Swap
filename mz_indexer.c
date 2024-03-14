/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_indexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:03:45 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 12:03:11 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mz_indexer(t_list *lst)
{
	int		index;
	t_list	*tmp;
	t_list	*tmp2;

	index = 1;
	while (index <= ft_lstsize(lst))
	{
		tmp = lst;
		tmp2 = NULL;
		while (tmp)
		{
			if (tmp->index == 0
				&& (tmp2 == NULL || tmp->content < tmp2->content))
				tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->index = index;
		index++;
	}
}
