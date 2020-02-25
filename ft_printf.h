/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:51:10 by lniki             #+#    #+#             */
/*   Updated: 2020/02/25 14:15:38 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "lib/libft.h"

 typedef  struct s_pr
    {
        char    *format;
        va_list *ap;

        int     nprinted; // количество выведенных символов

        int     i; // индекс строки формата
        int     len; // длина каждого аргумента

        int    minus; // -
        int    plus; // +
        int    space; // ' '
        int     zero; // 0
        int    hash; // #
           
        int     wdtx; //переменная для ширины
        // int     prec; // .#
        int     precf; // .
        int     leng; // hh h l ll L 
        
        char    spec; //переменная для спецификатора
                
    } t_pr;

    int     ft_printf(const char *format, ...);
    void    print_c(t_pr *mod);
    void    print_s(t_pr *mod);
    void   print_per(t_pr *mod);
    void   print_p(t_pr *mod);
    void   print_d(t_pr *mod);
    void   print_o(t_pr *mod);

#endif