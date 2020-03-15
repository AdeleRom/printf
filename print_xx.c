/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:31:25 by lniki             #+#    #+#             */
/*   Updated: 2020/03/15 18:42:08 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_xx(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    char *q; // строка для того чтоб туда записать конечный вид
    int i; // количество символов
    int r; // количество нолей или пробелов (ширина - длина строки)
    int check_0; //n

    if(mod->leng == 1)
        n = (unsigned long)( unsigned char)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 2)
        n = (unsigned long)( unsigned short int)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 3 || mod->leng == 4)
        n = va_arg(*(mod->ap), unsigned long int);
    else 
        n = (unsigned long)va_arg(*(mod->ap), unsigned int);

  
    l = n;
    i = 0;
    r = 0;
    q = 0;
    check_0 = 0; //n
    
    while(n > 0)
    {
        n = n / 16;
        i++;
    } 
    s = ft_strnew(l == 0 ? 1 : i); // если l = 0, то отправляем в стрнью ,если нет, то отправляем i.
    if(l == 0)
    {
        s[0] = '0';
        check_0 = 1; //n
    }
    while(l > 0)
    {
        if((l % 16) <= 9)
            s[--i] = (l % 16) + '0';
        else
            s[--i] = (l % 16) + 55; 
        l = l / 16;
    }
    
    while(l > 0)
    {
        s[--i] = (l % 10) + '0';
        l = l / 10;
    } 
    
    if(mod->zero == 1 && mod->hash == 0 && mod->precf == -1 && mod->wdtx > (int)ft_strlen(s))
         s = ft_strjoin("0", s);

    // точность
    if(mod->precf != -1)
    {
        if (mod->precf > (int)ft_strlen(s))
            r = mod->precf - ft_strlen(s);
        while(r--)
            s = ft_strjoin("0", s);
    }
    
    // хэш
    if(mod->hash == 1 && check_0 == 0 && 
    ((mod->zero == 1 && mod->precf <= 0) || ((mod->zero == 0 || (mod->zero == 1 && mod->precf > 0)) 
    && (mod->wdtx == mod->precf || mod->wdtx == 0 || mod->minus == 1 
    || (s[0] == '0' && mod->precf >= mod->wdtx)))))
        write(1, "0X", 2);
 
    
    // есть минус
    if(mod->minus == 1)
    {
        if ((mod->precf > 0 || mod->precf == -1)) //&& check_0 == 0)
            write(1, s, ft_strlen(s));
         else
            write(1, " ", 1);
      //  write(1, s, ft_strlen(s));
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(s) + ((mod->hash && check_0 == 0) ? 2 : 0))
                r = mod->wdtx - ft_strlen(s) - ((mod->hash && check_0 == 0) ? 2 : 0);
            while(r--)
                write(1, " ", 1);
        }
    }
     
    
    // нет минуса
    if(mod->minus == 0)
    {
        if(mod->wdtx && mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(s) + ((mod->hash && check_0 == 0) ? 2 : 0))
                r = mod->wdtx - ft_strlen(s) - ((mod->hash && check_0 == 0) ? 2 : 0);
            if(mod->zero == 1 && mod->precf <= 0)
            {
                while(r--)
                    write(1, "0", 1);
            }   
            else 
            {
                while(r--)
                    write(1, " ", 1);
                if(mod->hash == 1 && check_0 == 0)
                    write(1, "0X", 2);
            }
        }
        // if(mod->hash == 1 && check_0 == 0)
        //     s = ft_strjoin("0x", s);
        if ((mod->precf > 0 || mod->precf == -1)) //&& check_0 == 0)
            write(1, s, ft_strlen(s));
         //else
        if (mod->precf == 0 && mod->wdtx != 0 && check_0 == 1)   
             write(1, " ", 1);
       // if (mod->precf <= 0 && check_0 == 1)

        //if(check_0 == 1 && mod->wdtx && mod->precf <= 0)
        //    write(1, " ", 1);
    }
}