/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:56:47 by anakin            #+#    #+#             */
/*   Updated: 2024/10/20 18:07:06 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack_a)
{
    int min;
    min=get_min(stack_a);
    
    if((*stack_a)->index==min && (*stack_a)->next->index==(min+2))
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if((*stack_a)->index==(min+1))
    {
           if((*stack_a)->next->index==min)
            sa(stack_a);
        else if((*stack_a)->next->index==(min+2))
            rra(stack_a);
    }
    else if((*stack_a)->index==(min+2))
    {
           if((*stack_a)->next->index==min)
            ra(stack_a);
        else if((*stack_a)->next->index==(min+1))
            {
                sa(stack_a);
                rra(stack_a);
            }
    }
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = find_index(stack_a, get_min(stack_a));
    if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (checksorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}
void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = find_index(stack_a, get_min(stack_a));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (checksorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
void	sort(t_stack **stack_a ,t_stack **stack_b)
{
    int size;

    size = get_lstsize(*stack_a);
    if (size == 0||size== 1)
        return;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}