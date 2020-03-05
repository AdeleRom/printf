/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:36:38 by lniki             #+#    #+#             */
/*   Updated: 2020/03/05 22:42:38 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_d(t_pr *mod)
{
    long int n; // изначальное число
    long int l; // тоже самое, чтоб запомнить
    
    //long int z; // дополнительная переменная для сохранения 
    char q[2]; // строка для знака 
    char *s;
    int i;
    int r;

    i = 0;
    r = 0;
    
    //приведение типов
    if(mod->leng == 1)
        n = (long)(char)va_arg(*(mod->ap), int);
    else if(mod->leng == 2)
        n = (long)(short int)va_arg(*(mod->ap), int);
    else if(mod->leng == 3 || mod->leng == 4)
        n = va_arg(*(mod->ap), long int);
    else 
        n = (long)va_arg(*(mod->ap), int);
    
    l = n;
    
    //проверка знака
    if(n < 0)
        q[0] = '-';
    else if (mod->plus == 1 && n >= 0)
        q[0] = '+';
    else if (mod->space == 1 && n >= 0)
        q[0] = ' ';  
    
    //переводим в десятичный вид число
    while(n != 0)
    {
        n = n / 10;
        i++;
    }
    s = ft_strnew(l == 0 ? 1 : i); //выдеяем память для строки в которую будем записывать значение
    
    //проверка на 0
    if(l == 0 && mod->precf != 0) 
        s = ft_strjoin("0", s);

    //переводим число, записываем в s
    while(l != 0) 
    {
        if(l < 0 )
            s[--i] =   -(l % 10) + 48;
        else
             s[--i] =  (l % 10) + 48;
        l = l / 10;         
    }
   

    // хэш
    //if(mod->hash == 1 && s[0] != '0')
    //    s = ft_strjoin("0", s);

    // точность
    if(mod->precf != -1)
    {
        
        if (mod->precf > (int)ft_strlen(s))
            r = mod->precf - ft_strlen(s);
        while(r--)
            s = ft_strjoin("0", s);
    }
    
    // джойним знак
    if(mod->zero == 0 && (q[0] == '-' || q[0] == '+' || q[0] == ' '))
        s = ft_strjoin(q, s);
    
    // есть минус
    if(mod->minus == 1)
    {
        if (mod->zero == 1)
            s = ft_strjoin(q, s);
        write(1, s, ft_strlen(s));
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(s))
                r = mod->wdtx - ft_strlen(s);
            while(r--)
                write(1, " ", 1);
        }
    }
    
    // нет минуса
    if(mod->minus == 0)
    {
        
        if(mod->wdtx && mod->wdtx > mod->precf)
        {
            
            if (mod->wdtx > (int)ft_strlen(s))
                r = mod->wdtx - ft_strlen(s) - (sign(s, q) == 1 ? 1 : 0);

            if(mod->zero == 1 && mod->precf <= 0)
            {            
                if ((s[0] != '-' && s[0] != '+' && s[0] != ' ') && (q[0] == '-' || q[0] == '+' || q[0] == ' '))
                    write(1, q, 1);
                while(r--)
                    write(1, "0", 1);
            }   
            else 
            {
                while(r--)
                    write(1, " ", 1);
                if ((s[0] != '-' && s[0] != '+' && s[0] != ' ') && (q[0] == '-' || q[0] == '+' || q[0] == ' '))
                    write(1, q, 1);      
            }
        }
        else if (mod->zero == 1)
            s = ft_strjoin(q, s);
        write(1, s, ft_strlen(s));
    }
    q[0] = '0'; 
}

int sign(char* s, char* q)
{
    if ((s[0] != '-' && s[0] != '+' && s[0] != ' ') && (q[0] == '-' || q[0] == '+' || q[0] == ' '))
        return (1);
    return (0);
}