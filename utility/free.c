/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:18:48 by anakin            #+#    #+#             */
/*   Updated: 2024/10/19 21:02:00 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wp_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[--i]);
    free(str);
}

void	lst_free(t_stack **node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		(*node)->value = 0;
        (*node)->index = 0;
		free(*node);
		*node = tmp;
	}
	*node = NULL; 
}