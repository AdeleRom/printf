/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarpukova <tkarpukova@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:36:38 by lniki             #+#    #+#             */
/*   Updated: 2020/04/17 17:13:02 by tkarpukova       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int sign(char* s, char* q)
{
    if ((s[0] != '-' && s[0] != '+' && s[0] != ' ') && (q[0] == '-' || q[0] == '+' || q[0] == ' '))
        return (1);
    return (0);
}

void    no_minus_help(t_pr *mod, t_spec_d *spec)
{
    if (mod->wdtx > (int)ft_strlen(spec->s))
        spec->r = mod->wdtx - ft_strlen(spec->s) - (sign(spec->s, spec->q) == 1 ? 1 : 0);
    if(mod->zero == 1 && mod->precf <= 0)
    {            
        if ((spec->s[0] != '-' && spec->s[0] != '+' && spec->s[0] != ' ') && (spec->q[0] == '-' || spec->q[0] == '+' || spec->q[0] == ' '))
        { 
            write(1, spec->q, 1);
            mod->nprinted++;   
        }   
            
        while(spec->r)
        {
            write(1, "0", 1);
            spec->r--;
            mod->nprinted++;
        }    
    }   
    else 
    {
        while(spec->r)
        {
            write(1, " ", 1);
            mod->nprinted++;
            spec->r--;
        }    
        if ((spec->s[0] != '-' && spec->s[0] != '+' && spec->s[0] != ' ') && (spec->q[0] == '-' || spec->q[0] == '+' || spec->q[0] == ' ')) 
        {
            write(1, spec->q, 1);
            mod->nprinted++;
        }         
    }
}

void    if_no_minus_d(t_pr *mod, t_spec_d *spec)
{
    if(mod->wdtx && mod->wdtx > mod->precf)
        no_minus_help(mod, spec);
    /*
    ** здесь добавила условие (&& (spec->q[0] == ...)), что мы добавляем знак/пробел, если он есть
    ** иначе добавляется мусор/непечатные символы, потому что если знака нет у тебя spec->q[0] 
    ** не инициализирован и ничему не равен. Можно в функции check_sign_d в принципе, если нет знака,
    ** приравнивать spec->q[0] = 0, а потом когда джойнишь знак и строку проверять, что spec->q[0] != 0,
    ** но я не стала исправлять, сделала такое же условие, как у тебя в главной функции print_d
    */
    else if (mod->zero == 1 && (spec->q[0] == '-' || spec->q[0] == '+' || spec->q[0] == ' '))
        spec->s = ft_strjoin(spec->q, spec->s, 2);
    write(1, spec->s, ft_strlen(spec->s));
    mod->nprinted += ft_strlen(spec->s);
}

void    if_minus_d(t_pr *mod, t_spec_d *spec)
{
    if(mod->minus == 1)
    {
        /* точно так же как в if_no_minus_d добавила условие для проверки, 
        ** что мы джойним только если знак у нас точно есть
        */
        if (mod->zero == 1 && (spec->q[0] == '-' || spec->q[0] == '+' || spec->q[0] == ' '))
            spec->s = ft_strjoin(spec->q, spec->s, 2);
        write(1, spec->s, ft_strlen(spec->s));
        mod->nprinted += ft_strlen(spec->s);
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(spec->s))
                spec->r = mod->wdtx - ft_strlen(spec->s);
            while(spec->r)
            {
                write(1, " ", 1);
                mod->nprinted++;
                spec->r--;
            }    
        }
    }
}

void    decimal_conversion(t_pr *mod, t_spec_d *spec)
{
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
             spec->s[--spec->i] =  (spec->l % 10) + 48;
        spec->l = spec->l / 10;         
    }
}

void    check_sign_d(t_pr *mod, t_spec_d *spec)
{
    if(spec->n < 0)
        spec->q[0] = '-';
    else if (mod->plus == 1 && spec->n >= 0)
        spec->q[0] = '+';
    else if (mod->space == 1 && spec->n >= 0)
        spec->q[0] = ' ';
    /* 
    ** у тебя spec->q[2], то есть там обязательно должен быть элемент spec->q[0] и spec->q[1]
    ** иначе, если будет только spec->q[0] при присоединении spec->q и spec->s добавится мусор,
    ** который будет в spec->q[1], поэтому в spec->q[1] кладем \0
    */
    spec->q[1] = '\0';
}

void    type_d(t_pr *mod, t_spec_d *spec)
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

/* 
** добавила функцию для обработки точности
** из старого print_d_old (чтобы 0 ставились перед числом)
*/
void    check_precision(t_pr *mod, t_spec_d *spec)
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
}

void    print_d(t_pr *mod)
{
    t_spec_d spec;

    spec.i = 0;
    spec.r = 0;

    type_d(mod, &spec);
    spec.l = spec.n;
    check_sign_d(mod,&spec);
    decimal_conversion(mod, &spec);
    check_precision(mod, &spec);
    if(mod->zero == 0 && (spec.q[0] == '-' || spec.q[0] == '+' || spec.q[0] == ' '))
        spec.s = ft_strjoin(spec.q, spec.s, 2);
    if(mod->minus == 1)
        if_minus_d(mod, &spec);
    else if(mod->minus == 0)  /* сделала else if, вместо if - можешь вернуть обратно, если захочешь */
        if_no_minus_d(mod, &spec);
    spec.q[0] = '0'; 
    free(spec.s);
}