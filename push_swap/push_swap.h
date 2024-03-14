/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:18:54 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/13 12:31:26 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*mz_parser(char **s);
int		ft_atoi(const char *str, int *i, t_list **stack);
void	ft_swap(t_list **lst, int i);
void	ft_push(t_list **stack_1, t_list **stack_2, int i);
void	ft_rotate(t_list **lst, int i);
void	ft_reverse_rotate(t_list **lst, int i);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	mz_sort(t_list **stack_a, t_list **stack_b);
int		mz_is_sorted(t_list *lst);
void	mz_indexer(t_list *lst);
void	mz_sort_3(t_list **lst);
void	mz_position(t_list *stack_a, t_list *stack_b);
void	mz_target(t_list *stack_a, t_list *stack_b);
void	mz_cost(t_list *stack_a, t_list *stack_b);
void	mz_execute(t_list **stack_a, t_list **stack_b);

#endif
