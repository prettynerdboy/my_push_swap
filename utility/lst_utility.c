/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:12:38 by anakin            #+#    #+#             */
/*   Updated: 2024/10/20 17:44:14 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function return last node pointer.
*/
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
this funtion return size of list.
*/
int	get_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
this function return minumun index 
*/
int	get_min(t_stack **stack)
{
	t_stack	*head;
	int		min;

	if (!*stack)
		return(-1);
	head = *stack;
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}
/*
this function return distance　from the head  to the index
*/
int	find_index(t_stack **stack, int s_index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == s_index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
/*
this function return node that have min value ,and don't have index
*/
static t_stack *get_min_node(t_stack *stack)
{
    t_stack *tmp_head;
    t_stack *min_node;
    int flag;

    min_node =NULL;
    flag=0;
    tmp_head= stack;
    if (!tmp_head)
        return (NULL);
    while(tmp_head)
    {
        if((tmp_head->index== -1)&& (!flag||tmp_head->value<min_node->value))
        {
            min_node= tmp_head;
            flag=1;
        }
        tmp_head=tmp_head->next;
    }
    return(min_node);
}

/*
this function add index,in order of decreasing value.
*/
void	index_stack(t_stack *stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_min_node(stack);
	while (head)
	{
		head->index = index++;
		head = get_min_node(stack);
	}
}


