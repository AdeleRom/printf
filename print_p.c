/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:25:01 by lniki             #+#    #+#             */
/*   Updated: 2020/03/16 21:44:01 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_p(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    int i; // количество символов
    int check_0;
    int r;
    
    n = (unsigned long)va_arg(*(mod->ap), void*);
    l = n;
    i = 0;
    r = 0;
    check_0 = 0;
    
    while(n > 0)
    {
        n = n / 16;
        i++;
    } 
    s = ft_strnew(l == 0 ? 1 : i); // если l = 0, то отправляем в стрнью ,если нет, то отправляем i.
    if(l == 0)
    {
        s[0] = '0';
        check_0 = 1;
    }    
    
    while(l > 0)
    {
        if((l % 16) <= 9)
            s[--i] = (l % 16) + '0';
        else
            s[--i] = (l % 16) + 87; 
        l = l / 16;
    }
    
    if(check_0 == 1 && mod->precf <= 0 && !mod->wdtx)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        if (mod->precf != 0)
        {   
            write(1, "0", 1);
            mod->nprinted++;
        }
    }

     if(check_0 == 1 && mod->precf == -1 && mod->wdtx && mod->minus == 1)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        write(1, "0", 1);
        mod->nprinted++;
    }
    if(mod->minus == 1 && check_0 == 0)
    {
        write(1, "0x", 2);
        if(mod->precf > 0 && mod->wdtx && mod->precf > mod->wdtx)
        {
            r = ft_strlen(s) - 3;
            while (r  && r < mod->precf)
            {
                write(1, "0", 1);
                mod->nprinted++;
                r--;
            }
        }
        write(1, s, ft_strlen(s));
        mod->nprinted = ft_strlen(s) + 3;
    }
    
    while(mod->wdtx > (int)ft_strlen(s) + 2)
    {
        write(1, " ", 1);
        mod->nprinted++;
        mod->wdtx--;
    }
    
    if(mod->minus == 0 && check_0 == 0)
    {
        
        // if(check_0 == 1 && )
        write(1, "0x", 2); 
        
        if(mod->precf > 0 && mod->wdtx && mod->precf > mod->wdtx)
        {
            r = mod->precf - ft_strlen(s); //-3
            while (r  && r < mod->precf)
            {
                write(1, "0", 1);
                mod->nprinted++;
                r--;
            }
        }
        // if (check_0 && mod->precf <= 0) 
        // {
        //     mod->nprinted = mod->nprinted + 2;
        //     return ;
        // }
        write(1, s, ft_strlen(s));
        mod->nprinted = mod->nprinted + ft_strlen(s) + 2;

    }
    if(check_0 == 1 && mod->precf == -1 && mod->wdtx && mod->minus == 0)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        write(1, "0", 1);
        mod->nprinted++;
    }
    if(mod->precf > 0 && check_0 == 1)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        while(mod->precf)
        {
            write(1, "0", 1);
            mod->precf--;
            mod->nprinted++;
        }
    }
    free(s);
}