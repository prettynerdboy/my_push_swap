/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:07:41 by anakin            #+#    #+#             */
/*   Updated: 2024/10/19 20:58:02 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function make node,and return that node pointer.
*/
t_stack	*makenode(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/* 
this function make list.
If the head node is null, initialize at the node.
else, add the pointer of the received node ,to the last node next.
*/
void	node_add(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ; 
	if (!*stack)
		*stack = new_node;
	else
		(ft_lstlast(*stack))->next = new_node;
}


/*
this function make a stack with command line arguments.
*/
t_stack	*init_stack(int argc, char **argv)
{
    t_stack *head_node;
    t_stack *node;
    char **args;
    int i;

    head_node=NULL;
    i=0;
    if(argc==2)
        args=ft_split(argv[1],' ');
    else
       {
            args=argv;
            i = 1;
       }
    while(args[i])
    {
        node=makenode(ft_atoi(args[i]));
        node_add(&head_node, node);
        i++;
    }
    index_stack(head_node);
    if(argc == 2)
        wp_free(args);
    return (head_node);
}
