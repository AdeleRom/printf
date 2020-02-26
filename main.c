/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:21:46 by lniki             #+#    #+#             */
/*   Updated: 2020/02/26 16:42:28 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
    // ft_printf("%5.35c.\n", 'z');
	// printf("%5hd.\n", 'z');
	// printf("%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.\n", 48, 49, 50, 51, 52, 53, 54, 55, 56, 57);
	// ft_printf("jhtjhf%-5hhc.%2c.%1c.\n", 'z', 'd', 'a');
	// int c  = 0;
	// ft_printf("%-25p.\n", &c);
	
	//ft_printf("%o\n", 43);
	//printf("%o\n", 43);
	
	//ft_printf("%#5o\n", 3);
	//printf("%#5o\n", 3);
	
	ft_printf("%#5o\n", 43);
	printf("%#5o\n", 43);
	
	ft_printf("%#-5o\n", 43);
	printf("%#-5o\n", 43);
	
	//printf("this %o number\n", 17);
	//ft_printf("this %o number\n", 17);
	
	//ft_printf("%015.6d\n", 43);
	//printf("%015.6d\n", 43);
	
	//printf("%+3.7d", 3267);
	
	// printf("%-25p.\n", &c);
	
	// printf("%-5c.\n", 'z');
    return(0);
	// printf("hello%");
    // ft_printf("hello");
   
}