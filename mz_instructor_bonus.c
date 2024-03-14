/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_instructor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:49:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 20:41:55 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	mz_compare(char *str)
{
	if (ft_strcmp("sa\n", str) == 0)
		return (0);
	else if (ft_strcmp("sb\n", str) == 0)
		return (0);
	else if (ft_strcmp("ss\n", str) == 0)
		return (0);
	else if (ft_strcmp("ra\n", str) == 0)
		return (0);
	else if (ft_strcmp("rb\n", str) == 0)
		return (0);
	else if (ft_strcmp("rr\n", str) == 0)
		return (0);
	else if (ft_strcmp("rra\n", str) == 0)
		return (0);
	else if (ft_strcmp("rrb\n", str) == 0)
		return (0);
	else if (ft_strcmp("rrr\n", str) == 0)
		return (0);
	else if (ft_strcmp("pa\n", str) == 0)
		return (0);
	else if (ft_strcmp("pb\n", str) == 0)
		return (0);
	else
		return (1);
}

static void	mz_error_2(t_list **stack, t_list *new, t_list **stack_a)
{
	t_list	*ptr;

	write(2, "Error\n", 6);
	ft_lstclear(stack_a);
	free(new);
	if (!stack)
		exit(1);
	ptr = *stack;
	while (*stack)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr->ins);
		free(ptr);
	}
	*stack = NULL;
	exit(1);
}

static t_list	*ft_lstnew_char(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->ins = content;
	new->next = NULL;
	return (new);
}

t_list	*mz_instructor(t_list **stack_a)
{
	t_list	*lst;
	t_list	*new;
	char	*move;

	lst = NULL;
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		new = ft_lstnew_char(move);
		if (!new || mz_compare(move) == 1)
			mz_error_2(&lst, new, stack_a);
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}
