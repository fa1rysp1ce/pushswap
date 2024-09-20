/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:47 by junruh            #+#    #+#             */
/*   Updated: 2024/09/19 14:20:24 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(t_node **node)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *node;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	exit (0);
}

t_node	*find_end(t_node **node)
{
	t_node	*curr;

	if (*node == NULL)
		return (NULL);
	curr = *node;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}

int	count_stack(t_node **node)
{
	int		count;
	t_node	*curr;

	curr = *node;
	count = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

int	is_sorted(t_node *stack)
{
	t_node	*curr;

	curr = stack->next;
	while (curr != NULL)
	{
		if (curr->x < curr->prev->x)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	count_nums(char *arr[])
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
