/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:40:09 by junruh            #+#    #+#             */
/*   Updated: 2024/09/10 18:32:12 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftplus/includes/ft_printf.h"
# include "libftplus/includes/get_next_line.h"
# include "libftplus/includes/libft.h" 

typedef struct s_node
{
	int				x;
	int				index;
	int				median;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;


void	print_list(t_node **a, t_node **b);




int		main(int argc, char *argv[]);

void	tiny_sort(t_node **stack);
void	check_input(int argc, char *argv[]);
t_node	*fill_list(int argc, char *argv[]);
int		add_node(t_node **node, int value);
void	check_dups(t_node **node, int value);

//actions1

void	sa(t_node **stack);
void	sb(t_node **stack);
void	push(char direc, t_node **minus, t_node **plus);

//actions2

void	rrotate(char check, t_node **stack);
void	rrr(t_node **a, t_node **b);
void	rotate(char check, t_node **stack);
void	rr(t_node **a, t_node **b);

//helpers
void	exit_free(t_node **node);
t_node	*find_end(t_node **node);
int		count_stack(t_node **node);
int		is_sorted(t_node *stack);
int		count_nums(char *arr[]);

//helpers2
t_node	*find_biggest(t_node *stack);
t_node	*find_smallest(t_node *stack);
void	set_index(t_node **stack);
void	free_split(char **arr);

//sort
void	sort(t_node **a, t_node **b);
void	push_a(t_node **a, t_node **b);
t_node	*find_target_a(t_node *node, t_node **stack);

//push_b
void	push_b(t_node **a, t_node **b);
int		cost(t_node *node, t_node **a, t_node **b);
void	find_cheapest(t_node **a, t_node **b);
void	push_node(t_node *node, t_node **a, t_node **b);
t_node	*find_target(t_node *node, t_node **stack);

#endif