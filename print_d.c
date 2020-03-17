/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:36:38 by lniki             #+#    #+#             */
/*   Updated: 2020/03/17 17:43:49 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_precf_d(t_pr *mod, t_spec_o *spec)
{
    if(mod->precf != -1)
    {
        
        if (mod->precf > (int)ft_strlen(spec->s))
            spec->r = mod->precf - ft_strlen(spec->s);
        while(spec->r)
        {
            spec->s = ft_strjoin("0", spec->s, 2);
            spec->r--;
        }       
    }
    
    // джойним знак
    if(mod->zero == 0 && (spec->d[0] == '-' || spec->d[0] == '+' || spec->d[0] == ' '))
        spec->s = ft_strjoin(spec->d, spec->s, 2);
}
void    check_sign_d(t_pr *mod, t_spec_o *spec)
{
     if(spec->n < 0)
        spec->d[0] = '-';
    else if (mod->plus == 1 && spec->n >= 0)
        spec->d[0] = '+';
    else if (mod->space == 1 && spec->n >= 0)
        spec->d[0] = ' ';  
    
    //переводим в десятичный вид число
    while(spec->n != 0)
    {
        spec->n = spec->n / 10;
        spec->i++;
    }
    spec->s = ft_strnew(spec->l == 0 ? 1 : spec->i); //выдеяем память для строки в которую будем записывать значение
    
    //проверка на 0
    if(spec->l == 0 && mod->precf != 0) 
        spec->s = ft_strjoin("0", spec->s, 2);

    //переводим число, записываем в s
    while(spec->l != 0) 
    {
        if(spec->l < 0 )
            spec->s[--spec->i] =   -(spec->l % 10) + 48;
        else
            spec-> s[--spec->i] =  (spec->l % 10) + 48;
        spec->l = spec->l / 10;         
    }
}
void    type_d(t_pr *mod, t_spec_o *spec)
{
    if(mod->leng == 1)
        spec->n = (long)(char)va_arg(*(mod->ap), int);
    else if(mod->leng == 2)
        spec->n = (long)(short int)va_arg(*(mod->ap), int);
    else if(mod->leng == 3 || mod->leng == 4)
        spec->n = va_arg(*(mod->ap), long int);
    else 
        spec->n = (long)va_arg(*(mod->ap), int);
}
void   print_d(t_pr *mod)
{
    // long int n; // изначальное число
    // long int l; // тоже самое, чтоб запомнить
    
    // //long int z; // дополнительная переменная для сохранения 
    // char d[2]; // строка для знака 
    // char *s;
    // int i;
    // int r;
    t_spec_o spec;
    
    spec.i = 0;
    spec.r = 0;
    // spec->d = [2];
    
    type_d(mod, &spec);
    spec.l = spec.n;
    check_precf_d(mod, &spec);
    if(mod->minus == 1)
    {
        if (mod->zero == 1)
            spec.s = ft_strjoin(spec.d, spec.s, 2);
        write(1, spec.s, ft_strlen(spec.s));
        mod->nprinted += ft_strlen(spec.s);
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(spec.s))
                spec.r = mod->wdtx - ft_strlen(spec.s);
            while(spec.r)
            {
                write(1, " ", 1);
                mod->nprinted++;
                spec.r--;
            }    
        }
    }
    
    // нет минуса
    if(mod->minus == 0)
    {
        if(mod->wdtx && mod->wdtx > mod->precf)
        { 
            if (mod->wdtx > (int)ft_strlen(spec.s))
                spec.r = mod->wdtx - ft_strlen(spec.s) - (sign(spec.s, spec.d) == 1 ? 1 : 0);
            if(mod->zero == 1 && mod->precf <= 0)
            {            
                if (sign(spec.s, spec.d))
                { 
                    write(1, spec.d, 1);
                    mod->nprinted++;   
                }     
                while(spec.r)
                {
                    write(1, "0", 1);
                    spec.r--;
                    mod->nprinted++;
                }    
            }   
            else 
            {
                while(spec.r)
                {
                    write(1, " ", 1);
                    mod->nprinted++;
                    spec.r--;
                }    
                if (sign(spec.s, spec.d)) 
                {
                    write(1, spec.d, 1);
                    mod->nprinted++;
                }         
            }
        }
        else if (mod->zero == 1)
            spec.s = ft_strjoin(spec.d, spec.s, 2);
        write(1, spec.s, ft_strlen(spec.s));
        mod->nprinted += ft_strlen(spec.s);
    }
    spec.d[0] = '0'; 
    free(spec.s);
}

int sign(char* s, char* d)
{
    if ((s[0] != '-' && s[0] != '+' && s[0] != ' ') && (d[0] == '-' || d[0] == '+' || d[0] == ' '))
        return (1);
    return (0);
}