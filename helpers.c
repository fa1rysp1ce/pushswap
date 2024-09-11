/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:47 by junruh            #+#    #+#             */
/*   Updated: 2024/09/11 11:41:57 by junruh           ###   ########.fr       */
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
	exit (1);
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