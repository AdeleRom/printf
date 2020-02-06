/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:13:17 by lniki             #+#    #+#             */
/*   Updated: 2020/02/06 16:37:56 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   check_spec(t_pr *mod)
{
    if(mod->spec == 'd' || mod->spec == 'i')
        print_d(mod);
    // if(mod->spec == 'o')
    //     print_o(mod);
    // if(mod->spec == 'x')
    //     print_x(mod);
    // if(mod->spec == 'X')
    //     print_xx(mod);
    // if(mod->spec == 'u')
    //     print_u(mod);
    if(mod->spec == 'c')
        print_c(mod);
    if(mod->spec == 's')
        print_s(mod);
    // if(mod->spec == 'f')
    //     print_f(mod);
    if(mod->spec == 'p')
        print_p(mod);
    if(mod->spec == '%')
        print_per(mod);
}

int   check_flag(t_pr *mod, char *format)
{
    int i;

    i = 1;
    while(format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && 
        format[i] != 'x' && format[i] != 'X' && format[i] != 'u' && 
        format[i] != 'c' && format[i] != 's' && format[i] != 'f' &&
        format[i] != 'p' && format[i] != '%')
    {
        if(format[i] == '-')
            mod->minus = 1;
        if(format[i] == '+')
            mod->plus = 1;
        if(format[i] == ' ')
            mod->space = 1;
        if(format[i] == '0')
            mod->zero = 1;
        if(format[i] == '#')
            mod->hash = 1;
        if(format[i] >= '1' && format[i] <= '9')
        {
            mod->wdtx = ft_atoi(&format[i]);
            while(format[i] >= '0' && format[i] <= '9')
                i++;                
        } 
        if(format[i] == '.')
        {
            mod->precf = ft_atoi(&format[++i]);
            while(format[i] >= '0' && format[i] <= '9')
                i++;
        }
        if(format[i] == 'h' && format[i + 1] == 'h')
        {
            mod->leng = 1;
            i++;
        }
        else if(format[i] == 'l' && format[i + 1] == 'l')
        {
            mod->leng = 4;
            i++;
        }
        else if(format[i] == 'h')
            mod->leng = 2;
        else if(format[i] == 'l')
            mod->leng = 3;  
        else if(format[i] == 'L')
            mod->leng = 5;  
        if(format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && 
        format[i] != 'x' && format[i] != 'X' && format[i] != 'u' && 
        format[i] != 'c' && format[i] != 's' && format[i] != 'f' &&
        format[i] != 'p' && format[i] != '%')
            i++;
    }
    mod->spec = format[i];
    return(i);// не надо будет возращать ничего
}

void   fill(t_pr *mod)//, char *format)
{
    // mod->format = format;
    // mod->nprinted = 0;
    mod->i = 0;
    mod->len = 0;
    mod->minus = 0;
    mod->plus = 0;
    mod->space = 0;
    mod->zero = 0;
    mod->hash = 0;
    mod->wdtx = 0;
    // mod->prec = 0;
    mod->precf = -1;
    mod->leng = 0;
    mod->spec = '0';

}

int     mparser(t_pr *mod, char *format)
{
    int i;

    i = 0 ;
    fill(mod);
    mod->nprinted = 0;
    while(format[i])
    {
        if(format[i] != '%')
            write(1, &format[i], 1);
        else if (format[i] == '%')
        {
            i += check_flag(mod, &format[i]); // не надо будет прибавлять           
            check_spec(mod);
            fill(mod);
        }
            
        
        i++;
    }
    
    // printf("-%d +%d ' '%d  0%d  #%d  w%d p%d l%d\n", mod->minus, mod->plus, mod->space,
    //     mod->zero, mod->hash, mod->wdtx, mod->prec, mod->leng);
    return(1);
}

int     ft_printf(const char *format, ...)
{
    va_list ap; //список аргументов

	t_pr    *mod;// инициализирую структуру
    
    if (!((mod = (t_pr*)malloc(sizeof(t_pr)))))
        return (0);
	va_start(ap, format); //запускаем 
    mod->ap = &ap;
    mparser(mod, (char*)format);
	va_end(ap); 
    return(0);
}