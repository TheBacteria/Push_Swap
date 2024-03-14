/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:02:50 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/19 20:27:30 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				content;
	char			*ins;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*mz_strjoin(char const *s1, char const *s2);
size_t	mz_strlen(const char *s);
int		mz_strchr(const char *s, char c);
size_t	mz_strlcpy(char *dst, char *src, size_t dstsize);
char	*mz_strdup(const char *s1);
t_list	*mz_parser(char **s);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str, int *i, t_list **stack);
void	ft_swap(t_list **lst);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);
void	ft_push(t_list **stack_1, t_list **stack_2);
t_list	*mz_instructor(t_list **stack_a);
int		ft_lstsize(t_list *lst);

#endif