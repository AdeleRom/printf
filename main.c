/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:21:46 by lniki             #+#    #+#             */
/*   Updated: 2020/03/05 22:36:33 by lniki            ###   ########.fr       */
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
	
	//ft_printf("%08.5o\n", 34);
	//printf("%08.5o\n", 34);
	// ft_printf("this %o number", 17);
	// ft_printf("%5.2o\n", 53);
	// printf("%5.2o\n", 53);
	
	// printf("%7o\n", 33);
	
	// ft_printf("%7o\n", 33);

	//printf("%2o", 94827);
	//ft_printf("%.3o", 938862);
	////ft_printf("%+7d\n", 0);
//	printf("%+7d\n", 0);
	//ft_printf("%015.6d\n", 43);
	//printf("%015.6d\n", 43);
	
	//printf("%+3.7d", 3267);
	
	// printf("%-25p.\n", &c);
	
	// printf("%-5c.\n", 'z');
	ft_printf("%ld%hhd%hd\n", -22337203685477, 100, 3047);
	//printf("%ld%hhd%hd", -22337203685477, 100, 3047);
    return(0);
	// printf("hello%");
    // ft_printf("hello");
   
}