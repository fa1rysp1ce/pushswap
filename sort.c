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
	print_list(a, &b);
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
		find_cheapest(b, a);
		print_list(a, b);
	}
	print_list(a, b);
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
