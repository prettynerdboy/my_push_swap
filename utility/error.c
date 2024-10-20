/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:22:51 by anakin            #+#    #+#             */
/*   Updated: 2024/10/19 22:32:43 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *msg)
{	
    const char *red = "\033[31m"; 
    const char *reset = "\033[0m"; 
    write(2, red, 5);                
    ft_putendl_fd(msg, 1) ;      
    write(2, reset, 4); 
    exit(1);
}

// int main(void)
// {
//     ft_error("errorabc");
//     return(0);
// }