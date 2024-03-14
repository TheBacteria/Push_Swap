/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:45:06 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/20 14:18:48 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	mz_free_stacks(t_list **sa, t_list **sb, t_list **si, int i)
{
	t_list	*ptr;

	ft_lstclear(sa);
	ft_lstclear(sb);
	if (!si)
		return ;
	ptr = *si;
	while (*si)
	{
		ptr = *si;
		*si = (*si)->next;
		free(ptr->ins);
		free(ptr);
	}
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	mz_is_sorted_2(t_list *lst, t_list *lst2)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->content < tmp->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = lst;
		lst = lst->next;
	}
	if (!lst2)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static size_t	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	mz_make_move(t_list **sa, t_list **sb, t_list **sti, char *si)
{
	if (ft_strcmp("sa\n", si) == 0)
		ft_swap(sa);
	else if (ft_strcmp("sb\n", si) == 0)
		ft_swap(sb);
	else if (ft_strcmp("ss\n", si) == 0)
		ft_ss(sa, sb);
	else if (ft_strcmp("ra\n", si) == 0)
		ft_rotate(sa);
	else if (ft_strcmp("rb\n", si) == 0)
		ft_rotate(sb);
	else if (ft_strcmp("rr\n", si) == 0)
		ft_rr(sa, sb);
	else if (ft_strcmp("rra\n", si) == 0)
		ft_reverse_rotate(sa);
	else if (ft_strcmp("rrb\n", si) == 0)
		ft_reverse_rotate(sb);
	else if (ft_strcmp("rrr\n", si) == 0)
		ft_rrr(sa, sb);
	else if (ft_strcmp("pa\n", si) == 0)
		ft_push(sb, sa);
	else if (ft_strcmp("pb\n", si) == 0)
		ft_push(sa, sb);
	else
		mz_free_stacks(sa, sb, sti, 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_i;
	t_list	*tmp;

	if (2 > argc)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	stack_i = NULL;
	stack_a = mz_parser(argv);
	if (stack_a == NULL)
		exit(1);
	stack_i = mz_instructor(&stack_a);
	tmp = stack_i;
	while (tmp)
	{
		mz_make_move(&stack_a, &stack_b, &stack_i, tmp->ins);
		tmp = tmp->next;
	}
	mz_is_sorted_2(stack_a, stack_b);
	mz_free_stacks(&stack_a, &stack_b, &stack_i, 0);
}
