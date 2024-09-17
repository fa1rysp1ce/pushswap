#include "push_swap.h"

void	push_b(t_node **a, t_node **b)
{
	t_node *curr;

	while (count_stack(a) > 3)
	{
		set_index(a);
		set_index(b);
		curr = *a;
		while (curr != NULL)
		{
			curr->target = find_target(curr, b);
			curr = curr->next;
		}
		find_cheapest(a, b);
	}
	tiny_sort(a);
	print_list(a, b);
}

int	cost(t_node *node, t_node **a, t_node **b)
{
	int	cost;

	if (node->median == 0)
		cost = node->index;
	else
		cost = count_stack(a) - node->index;
	if (node->target->median == 0)
		cost += node->target->index;
	else
		cost += count_stack(b) - node->target->index;
	return (cost);
}

void	find_cheapest(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*curr;

	cheapest = *a;
	curr = *a;
	while (curr != NULL)
	{
		if (cost(cheapest, a, b) > cost(curr, a, b))
			cheapest = curr;
		curr = curr->next;
	}
	push_node(cheapest, a, b);
}

void	push_node(t_node *node, t_node **a, t_node **b)
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
			rotate('a', a);
		if (node->median == 1)
			rrotate('a', a);
		print_list(a, b);
	}
	while (node->target->prev != NULL)
	{
		if (node->target->median == 0)
			rotate('b', b);
		if (node->target->median == 1)
			rrotate('b', b);
		print_list(a, b);
	}
	push('b', a, b);
}

t_node	*find_target(t_node *node, t_node **stack)
{
	t_node	*curr;
	t_node	*closest;

	curr = *stack;
	closest = NULL;
	while (curr != NULL)
	{
		if (closest != NULL && curr->x < node->x && curr->x > closest->x)
			closest = curr;
		else if (curr->x < node->x && closest == NULL)
			closest = curr;
		curr = curr->next;
	}
	if (closest == NULL)
		closest = find_biggest(*stack);
	return (closest);
}