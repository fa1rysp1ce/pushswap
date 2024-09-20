/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:59 by junruh            #+#    #+#             */
/*   Updated: 2024/09/19 18:26:04 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->x;
	(*stack)->x = (*stack)->next->x;
	(*stack)->next->x = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->x;
	(*stack)->x = (*stack)->next->x;
	(*stack)->next->x = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	int	tmp;

	tmp = (*a)->x;
	(*a)->x = (*a)->next->x;
	(*a)->next->x = tmp;
	tmp = (*b)->x;
	(*b)->x = (*b)->next->x;
	(*b)->next->x = tmp;
	write(1, "ss\n", 3);
}

void	push(char direc, t_node **minus, t_node **plus)
{
	t_node	*tmp;

	if (*minus == NULL)
		return ;
	tmp = (*minus)->next;
	(*minus)->next = *plus;
	if (*plus != NULL)
		(*plus)->prev = *minus;
	*plus = *minus;
	*minus = tmp;
	if (*minus != NULL)
		(*minus)->prev = NULL;
	if (direc == 'a')
		write(1, "pa\n", 3);
	else if (direc == 'b')
		write(1, "pb\n", 3);
}
