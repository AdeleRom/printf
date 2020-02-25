/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:36:38 by lniki             #+#    #+#             */
/*   Updated: 2020/02/17 18:09:26 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_d(t_pr *mod)
{
    long int l; // bpyfxfkmyjt xbckj
    long int n; // число, чтоб запомнить
    long int z; // дополнительная переменная для сохранения 
    char *q; // строка для знака 
    char *s;
    int i;
    int x;

    i = 0;
    x = 0;
    
    //приведение типов
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

    //переводим в десятичный вид число
    while(l != 0)
    {
        l = l / 10;
        i++;
    }
    s = ft_strnew(n == 0 ? 1 : i); //выдеяем память для строки в которую будем записывать значение
    
    if(n == 0) //проверка 
        s[0] = '0';
    
    while(n != 0) 
    {
        if(n < 0 )
            s[--i] =   -(n % 10) + 48;
        else
             s[--i] =  (n % 10) + 48;
        n = n / 10;         
    }
    
    q = ft_strnew(1);
    //обработка флагов     
    if(z < 0)
        q[0] = '-';
    else if (mod->plus == 1 && z >= 0)
        q[0] = '+';
    else if (mod->space == 1 && z >= 0)
        q[0] = ' ';
    
    while(mod->precf > (int)ft_strlen(s))
    {
        s = ft_strjoin("0", s);
        // mod->precf;
    }
     s = ft_strjoin(q, s);

    if(mod->minus == 1)
    {
       while (s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
    
    while(mod->wdtx > (int)ft_strlen(s))
    {
        if(mod->zero == 1 && mod->precf == -1)
            write(1, "0", 1);
        else
            write(1, " ", 1);
        mod->wdtx--;   
    }
    
    // обработка ширины
    while(mod->wdtx > (int)ft_strlen(s))
    {
        if(mod->zero == 1 && mod->precf == -1)
            write(1, "0", 1);
        else
            write(1, " ", 1);
        mod->wdtx--;   
    }

    if(mod->minus == 0)
    {
       while (s[i])
        {
            write(1, &s[i], 1);
            i++;
        }
    }
}