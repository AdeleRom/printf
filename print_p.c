/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:25:01 by lniki             #+#    #+#             */
/*   Updated: 2020/02/14 18:22:37 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_p(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    int i; // количество символов
    
    n = (unsigned long)va_arg(*(mod->ap), void*);
    l = n;
    i = 0;
    
    while(n > 0)
    {
        n = n / 16;
        i++;
    } 
    s = ft_strnew(l == 0 ? 1 : i); // если l = 0, то отправляем в стрнью ,если нет, то отправляем i.
    if(l == 0)
        s[0] = '0'; 
    while(l > 0)
    {
        if((l % 16) <= 9)
            s[--i] = (l % 16) + '0';
        else
            s[--i] = (l % 16) + 87; 
        l = l / 16;
    }
    
    if(mod->minus == 1)
    {
        write(1, "0x", 2);
        write(1, s, ft_strlen(s));
    }
    while(mod->wdtx > (int)ft_strlen(s) + 2)
    {
        write(1, " ", 1);
        mod->wdtx--;
    }
    if(mod->minus == 0)
    {
        write(1, "0x", 2);
        write(1, s, ft_strlen(s));
    }
}