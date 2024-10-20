/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:05:23 by anakin            #+#    #+#             */
/*   Updated: 2024/10/20 18:11:22 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap_h
#define push_swap_h

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//main

int	checksorted(t_stack *stack);

//validation

void	check_args(int argc, char **argv);

//sort

void	radix_sort(t_stack **stack_a, t_stack **stack_b);

//minilib

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
int	    ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int	    ft_atoi(const char *str);

//lstutil

t_stack	*ft_lstlast(t_stack *lst);
int	    get_lstsize(t_stack *lst);
int	    get_min(t_stack **stack);
int	    find_index(t_stack **stack, int index);
void	index_stack(t_stack *stack);

//initstack

t_stack	*makenode(int value);
void	node_add(t_stack **stack, t_stack *new_node);
t_stack	*init_stack(int argc, char **argv);

//sortfunction
void	sort(t_stack **stack_a ,t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a,t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a,t_stack **stack_b);

//extra

void    ft_error(char *msg);
void	wp_free(char **str);
void	lst_free(t_stack **node);
#endif