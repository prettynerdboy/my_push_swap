/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:09:15 by anakin            #+#    #+#             */
/*   Updated: 2024/10/20 18:57:13 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
this function check list is	sorted(1), or not(0)
*/
int	checksorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		ft_error("error");
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_args(argc, argv);
	a = init_stack(argc, argv);
	b = NULL;
	if (!a)
	{
		ft_error("Failure to initialize stack");
		lst_free(&a);
	}
	while (!checksorted(a))
		sort(&a, &b);
	lst_free(&a);
	return (0);
}

// this function check stack is initialized , with correct arg
// and test function checksorted

// int	main(int argc, char **argv)
// {
// 	t_stack *a;
// 	check_args(argc, argv);
// 	a = init_stack(argc, argv);

// 	int i;
//     t_stack *head;
// 	i = 0;
//     head=a;
// 	while (a)
// 	{
// 		printf("node[%d]=%d,index=%d\n", i, a->value,a->index);
// 		a = a->next;
// 		i++;
// 	}
//     a=head;
//     if(checksorted(a))
//         printf("sorted\n");
//     else
//         printf("not sorted\n");
// 	lst_free(&a);
// 	return (0);
// }

// chec operation

// int	main(int argc, char **argv)
// {
// 	t_stack *a;
//     t_stack *b;
//     int i;
//     t_stack *head;

// 	check_args(argc, argv);
// 	a = init_stack(argc, argv);
//     b = NULL;
//     head=a;
// 	while (a)
// 	{
// 		printf("node=%d,index=%d\n", a->value,a->index);
// 		a = a->next;
// 	}
//     printf("stack,init!\n");
//     a=head;
//     while (!checksorted(a))
// 		sort(&a,&b);
//     while (a)
// 	{
// 		printf("node=%d,index=%d\n",a->value,a->index);
// 		a = a->next;
// 	}
//     lst_free(&a);
//     a=head;
//     return(0);
// }