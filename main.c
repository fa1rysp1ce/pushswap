/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:40:27 by junruh            #+#    #+#             */
/*   Updated: 2024/09/19 19:40:19 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	char	**arr;
	int		checker;

	checker = 0;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		argc = count_nums(arr) + 1;
		checker = 1;
	}
	else
		arr = argv + 1;
	check_input(argc - 1, arr);
	a = fill_list(argc - 1, arr);
	if (checker == 1)
		free_split(arr);
	if (is_sorted(a) == 0)
		exit_free(&a);
	if (argc <= 4)
		tiny_sort(&a);
	else if (argc > 4)
		sort(&a, argc);
	exit_free(&a);
}

void	check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc < 1)
		exit(1);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				write(2, "Error\n", 6);
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

	i = 0;
	node = NULL;
	while (i < argc)
	{
		if (argv[i][1] == '\0' && argv[i][0] == '-')
		{
			
		}
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648 || (argv[i][1] == '\0' && argv[i][0] == '-'))
		{
			write(2, "Error\n", 6);
			exit_free(&node);
		}
		check_dups(&node, num);
		if (add_node(&node, num) != 0)
			exit_free(&node);
		i++;
	}
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
			write(2, "Error\n", 6);
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
/*
void	print_list(t_node **a)
{
	ft_printf("-------------\na:\n");
	for(t_node *curr = *a; curr != NULL; curr = curr->next)
		ft_printf("%d\n", curr->x);
	//ft_printf("\nb:\n");
	//for(t_node *curr = *b; curr != NULL; curr = curr->next)
	//	ft_printf("%d\n", curr->x);
}*/