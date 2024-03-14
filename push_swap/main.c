/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:24:41 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/20 14:18:35 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (2 > argc)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = mz_parser(argv);
	if (stack_a == NULL)
		exit(1);
	mz_indexer(stack_a);
	if (ft_lstsize(stack_a) <= 3)
		mz_sort_3(&stack_a);
	else
		mz_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
