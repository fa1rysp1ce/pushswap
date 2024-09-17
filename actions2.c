/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:06:14 by junruh            #+#    #+#             */
/*   Updated: 2024/09/11 13:07:09 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(char check, t_node **stack)
{
	t_node	*last_node;
	
	last_node = find_end(stack);
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	(*stack) = last_node;
	if (check == 'a')
		write(1, "rra\n", 4);
	if (check == 'b')
		write(1, "rrb\n", 4);
}
void	rrr(t_node **a, t_node **b)
{
	rrotate('r', a);
	rrotate('r', b);
	write(1, "rrr\n", 4);
	print_list(a, b);
}

void	rotate(char check, t_node **stack)
{
	t_node	*last_node;
	
	last_node = find_end(stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	if (check == 'a')
		write(1, "ra\n", 4);
	if (check == 'b')
		write(1, "rb\n", 4);
}

void	rr(t_node **a, t_node **b)
{
	rotate('r', a);
	rotate('r', b);
	write(1, "rr\n", 4);
	print_list(a, b);
}
