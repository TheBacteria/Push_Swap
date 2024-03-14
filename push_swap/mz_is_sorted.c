/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:43:00 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 12:04:08 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mz_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->content < tmp->content)
			return (1);
		tmp = lst;
		lst = lst->next;
	}
	return (0);
}
