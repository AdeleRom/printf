/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:36:38 by lniki             #+#    #+#             */
/*   Updated: 2020/02/06 20:04:13 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_d(t_pr *mod)
{
    long int l;
    long int n;
    long int z;
    char *s;
    int i;

    i = 0;
    
    
    if(mod->leng == 1)
        l = (long)(char)va_arg(*(mod->ap), int);
    else if(mod->leng == 2)
        l = (long)(short int)va_arg(*(mod->ap), int);
    else if(mod->leng == 3 || mod->leng == 4)
        l = va_arg(*(mod->ap), long int);
    else 
        l = (long)va_arg(*(mod->ap), int);
    
    n = l;
    z = l; 
    
    while(l != 0)
    {
        l = l / 10;
        i++;
    }
    s = ft_strnew(n == 0 ? 1 : i);
    if(n == 0)
        s[0] = '0';
    
    while(n != 0)
    {
        if(n < 0 )
            s[--i] =   -(n % 10) + 48;
        else
             s[--i] =  (n % 10) + 48;
        n = n / 10;         
    }
    
    if(mod->minus == 1)
    {
        if(z < 0)
            write(1, "-", 1);
        else if(mod->plus == 1)
            write(1, "+", 1);
        else if(mod->space == 1)
            write(1, " ", 1);

        while (s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
    while(mod->wdtx > (int)ft_strlen(s) + (z < 0 || mod->plus || mod->space ? 1 : 0))
    {
        write(1, " ", 1);
        mod->wdtx--;   
    }
    if(mod->minus == 0)
    {
        if(z < 0)
            write(1, "-", 1);
        else if(mod->plus == 1)
            write(1, "+", 1);
        else if(mod->space == 1)
            write(1, " ", 1);
                    
       while(s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
    
}