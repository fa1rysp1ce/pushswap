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

void	sort(t_node **a, int count)
{
	t_node	*b;
	t_node	*smallest;

	b = NULL;
	if (count == 6)
		sort_five(a, &b);
	else if (count == 5)
		sort_four(a, &b);
	else
	{
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
}

void	sort_five(t_node **a, t_node **b)
{
	smallest_on_top(a);
	if (is_sorted(*a) == 1)
	{
		push('b', a, b);
		sort_four(a, b);
		push('a', b, a);
	}
}

void	sort_four(t_node **a, t_node **b)
{
	smallest_on_top(a);
	if (is_sorted(*a) == 1)
	{
		push('b', a, b);
		tiny_sort(a);
		push('a', b, a);
	}
}

void	tiny_sort(t_node **stack)
{
	if (count_stack(stack) == 3)
	{
		if (*stack == find_biggest(*stack))
			rotate('a', stack);
		else if ((*stack)->next == find_biggest(*stack))
			rrotate('a', stack);
	}
	if ((*stack)->x > (*stack)->next->x)
		sa(stack);
}

void	smallest_on_top(t_node **a)
{
	t_node	*smallest;

	smallest = find_smallest(*a);
	set_index(a);
	if (smallest->median == 0)
	{
		while (smallest != *a)
			rotate('a', a);
	}
	if (smallest->median == 1)
	{
		while (smallest != *a)
			rrotate('a', a);
	}
}
