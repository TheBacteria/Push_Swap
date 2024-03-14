# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 18:07:18 by mzouine           #+#    #+#              #
#    Updated: 2024/02/20 11:54:16 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_atoi.c ft_lstadd_back.c ft_lstclear.c ft_lstlast.c ft_lstnew.c\
		ft_lstsize.c ft_rr.c ft_rrr.c mz_execute.c mz_cost.c mz_indexer.c mz_is_sorted.c\
		mz_sort.c mz_target.c mz_sort_3.c mz_position.c mz_parser.c ft_swap.c ft_ss.c ft_rotate.c\
		ft_reverse_rotate.c ft_push.c

SRC_BONUS = checker_bonus.c ft_push_bonus.c get_next_line_bonus.c ft_reverse_rotate_bonus.c\
			get_next_line_utils_bonus.c ft_atoi_bonus.c ft_rotate_bonus.c mz_instructor_bonus.c\
			ft_lstadd_back_bonus.c ft_rr_bonus.c mz_parser_bonus.c ft_lstclear_bonus.c\
			ft_rrr_bonus.c ft_lstlast_bonus.c ft_ss_bonus.c ft_lstnew_bonus.c ft_swap_bonus.c\
			ft_lstsize_bonus.c

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = cc
HEADER_BONUS = push_swap_bonus.h
HEADER = push_swap.h
RM = rm -f
NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

