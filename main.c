/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:40:27 by junruh            #+#    #+#             */
/*   Updated: 2024/09/11 17:29:00 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*root;
	
	check_input(argc, argv);
	root = fill_list(argc, argv);
	exit_free(&root);
}
/*
void	tester(t_node *root)
{
	int arr[] = {1, 2, 3, 4, 5}
	t_node *b;
	
}
*/
void	check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 3)
	{
		ft_printf("Error\nNot enough numbers to sort\n");
		exit(1);
	}
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				ft_printf("Error\nInput must only be numbers\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

t_node	*fill_list(int argc, char *argv[])
{
	t_node	*node;
	int		i;
	long	num;

	i = 1;
	node = NULL;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_printf("Error\nInput must be integer\n");
			exit_free(&node);
		}
		check_dups(&node, num);
		if (add_node(&node, num) != 0)
			exit_free(&node);
		i++;
	}
	for(t_node *curr = node; curr != NULL; curr = curr->next)
		ft_printf("%d\n", curr->x);
	return (node);
}

void	check_dups(t_node **node, int value)
{
	t_node	*curr;
	
	curr = *node;
	while (curr != NULL)
	{
		if (curr->x == value)
		{
			ft_printf("Error\nDuplicates found\n");
			exit_free(node);
		}
		curr = curr->next;
	}
}

int	add_node(t_node **node, int value)
{
	t_node	*new_node;
	t_node	*curr;
	
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->next = NULL;
	new_node->x = value;
	if (*node == NULL)
	{
		new_node->prev = NULL;
		*node = new_node;
		return (0);
	}
	curr = *node;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	new_node->prev = curr;
	curr->next = new_node;
	return (0);
}
