/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junruh <junruh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:40:09 by junruh            #+#    #+#             */
/*   Updated: 2024/09/10 18:32:12 by junruh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftplus/includes/ft_printf.h"
# include "libftplus/includes/get_next_line.h"
# include "libftplus/includes/libft.h" 

typedef struct s_node
{
	int	x;
	struct s_node *next;
	struct s_node *prev;
} t_node;

int		main(int argc, char *argv[]);

void	check_input(int argc, char *argv[]);
t_node	*fill_list(int argc, char *argv[]);
int		add_node(t_node **node, int value);
void	check_dups(t_node **node, int value);

void	exit_free(t_node **node);

#endif