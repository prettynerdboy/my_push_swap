/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:29:50 by anakin            #+#    #+#             */
/*   Updated: 2024/10/20 15:16:35 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// operation SWAP
static void	swap(t_stack **stack)
{
	t_stack *tmp;
    if (!*stack || !((*stack)->next))
		return ;
    tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
// swap stackA
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}
// swap stackB
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

// operation PUSH
static void	push(t_stack **push_s, t_stack **pull_s)
{
	t_stack	*tmp;

	if (!*push_s)
		return ;
	tmp = *pull_s;
	*pull_s = *push_s;
	*push_s = (*push_s)->next;
	(*pull_s)->next = tmp;
}
//push node to stackA from stackB
void	pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b,stack_a);
	ft_putendl_fd("pa", 1);
}

//push node to stackB from stackA
void	pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a,stack_b);
	ft_putendl_fd("pb", 1);
}

//operation ROTATE
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

//rotate stackA
void ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putendl_fd("ra", 1);
}
//rotate stackB
void rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putendl_fd("rb", 1);
}

//rotate stack A and B
void rr(t_stack **stack_a,t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

//operation REVERSE ROTATE
static void	reverse_rotate(t_stack **b)
{
	t_stack	*tmp;
	int		size;

	if (!*b || !(*b)->next)
		return ;
	size = get_lstsize(*b);
	tmp = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = tmp;
	while (--size > 1)
		tmp = tmp->next;
	tmp->next = NULL;
}
//reverse rotate stackA
void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_putendl_fd("rra", 1);
}
//reverse rotate stackB
void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_putendl_fd("rrb", 1);
}
//reverse rotate stack A and B
void rrr(t_stack **stack_a,t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}


