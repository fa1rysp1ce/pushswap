/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:30:15 by junruh            #+#    #+#             */
/*   Updated: 2024/09/19 19:39:43 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a)
{
	t_node	*b;
	t_node	*smallest;

	b = NULL;
	push('b', a, &b);
	push('b', a, &b);
	push_b(a, &b);
	push_a(a, &b);
	smallest = find_smallest(*a);
	while (is_sorted(*a) == 1)
	{
		if (smallest->median == 0)
			rotate('a', a);
		else
			rrotate('a', a);
	}
}

void	push_a(t_node **a, t_node **b)
{
	t_node	*curr;

	while ((*b) != NULL)
	{
		set_index(a);
		set_index(b);
		curr = *b;
		while (curr != NULL)
		{
			curr->target = find_target_a(curr, a);
			curr = curr->next;
		}
		find_cheapest_a(a, b);
	}
}

void	find_cheapest_a(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*curr;

	cheapest = *b;
	curr = *b;
	while (curr != NULL)
	{
		if (cost(cheapest, b, a) > cost(curr, b, a))
			cheapest = curr;
		curr = curr->next;
	}
	push_node_a(cheapest, a, b);
}

void	push_node_a(t_node *node, t_node **a, t_node **b)
{
	if (node->median == 0 && node->target->median == 0)
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rr(a, b);
	}
	if (node->median == 1 && node->target->median == 1)
	{
		while (node->prev != NULL && node->target->prev != NULL)
			rrr(a, b);
	}
	while (node->prev != NULL)
	{
		if (node->median == 0)
			rotate('b', b);
		if (node->median == 1)
			rrotate('b', b);
	}
	while (node->target->prev != NULL)
	{
		if (node->target->median == 0)
			rotate('a', a);
		if (node->target->median == 1)
			rrotate('a', a);
	}
	push('a', b, a);
}

t_node	*find_target_a(t_node *node, t_node **stack)
{
	t_node	*curr;
	t_node	*closest;

	curr = *stack;
	closest = NULL;
	while (curr != NULL)
	{
		if (closest != NULL && curr->x > node->x && curr->x < closest->x)
			closest = curr;
		else if (curr->x > node->x && closest == NULL)
			closest = curr;
		curr = curr->next;
	}
	if (closest == NULL)
		closest = find_smallest(*stack);
	return (closest);
}
