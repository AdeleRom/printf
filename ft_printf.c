/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:51:18 by lniki             #+#    #+#             */
/*   Updated: 2020/02/04 14:37:36 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
// #include <stdarg.h>
// #include "lib/libft.h"

// void	ft_chekpozb(char s) //проверка позиции
//  {
// 	int n;

// 	n = s - '0';
	
// 	while(n != 1)
// 	{
// 		write(1, " ", 1);
// 		n--;
// 	}
// }

// int    ft_chekc(va_list *ap) //проверка с 
// {
//     char c;

// 	c = va_arg(*ap, int);
// 	write(1, &c, 1);
// 	return(0);
	
// }

// int ft_chekpr(const char *n, va_list *ap) //функция проверки %
// {
//     int i;

//     i = 0;
//     while(n[i])
//     {
// 		if(n[i] == '-')
// 		{
// 			ft_chekc(ap);
// 			i++;
// 			ft_chekpozb(n[i]);
// 			return(i+1);
// 		}
// 		else if(n[i] >= '0' && n[i] <= '9')
// 		{
// 			// printf("!\n");
// 			// ft_putnbr(i);
// 			ft_chekpozb(n[i]);
// 			ft_chekc(ap);
// 			return(i+1);
// 		}		
// 		// else if(n[i] == 'c')
// 		// {
// 		// 	ft_chekc(ap);
// 		// 	return(i);
// 		// }
//         i++;
//     }
// 	return(i);
// }

// int     ft_printf(const char *format, ...)
// {
//     va_list ap; //список аргументов

// 	int i;

//     i = 0;
// 	va_start(ap, format);
//     while(format[i])
//     {
//         if (format[i] == '%')
//             i = ft_chekpr(&format[i], &ap);
//         else if (format[i] != '%')
//             write(1, &format[i], 1);
//     	if (format[i])
// 			i++;
//     }
// 	va_end(ap); 
//     return(0);
// }

// int main()
// {
//     // ft_printf("%5c.\n", 'z');
// 	// printf("%5c.\n", 'z');
// 	// printf("\n");
// 	ft_printf("%-5c.\n", 'z');
// 	printf("%-5c.\n", 'z');
//     return(0);
// 	// printf("hello");
//     // ft_printf("hello");
   
// }
