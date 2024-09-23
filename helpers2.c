/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:29:29 by junruh            #+#    #+#             */
/*   Updated: 2024/09/19 18:14:44 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node	*find_biggest(t_node *stack)
{
	t_node	*biggest;
	t_node	*curr;

	curr = stack;
	biggest = stack;
	while (curr != NULL)
	{
		if (curr->x > biggest->x)
			biggest = curr;
		curr = curr->next;
	}
	return (biggest);
}

void	set_index(t_node **stack)
{
	t_node	*curr;
	int		index;

	curr = *stack;
	index = 0;
	while (curr != NULL)
	{
		curr->index = index;
		if ((count_stack(stack) / 2) > index)
			curr->median = 0;
		else
			curr->median = 1;
		index++;
		curr = curr->next;
	}
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*smallest;
	t_node	*curr;

	curr = stack;
	smallest = stack;
	while (curr != NULL)
	{
		if (curr->x < smallest->x)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
