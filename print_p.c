/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:25:01 by lniki             #+#    #+#             */
/*   Updated: 2020/03/17 16:28:51 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_p(t_pr *mod, t_spec_o *spec)
{
    if(spec->check_0 == 1 && mod->precf == -1 && mod->wdtx && mod->minus == 0)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        write(1, "0", 1);
        mod->nprinted++;
    }
    if(mod->precf > 0 && spec->check_0 == 1)
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
}

void    if_no_minus_p(t_pr *mod, t_spec_o *spec)
{
    if(mod->minus == 0 && spec->check_0 == 0)
    {
        write(1, "0x", 2); 
        if(mod->precf > 0 && mod->wdtx && mod->precf > mod->wdtx)
        {
            spec->r = mod->precf - ft_strlen(spec->s); //-3
            while (spec->r  && spec->r < mod->precf)
            {
                write(1, "0", 1);
                mod->nprinted++;
                spec->r--;
            }
        }
        write(1, spec->s, ft_strlen(spec->s));
        mod->nprinted = mod->nprinted + ft_strlen(spec->s) + 2;

    }
}

void    if_minus_p(t_pr *mod, t_spec_o *spec)
{
    if(mod->minus == 1 && spec->check_0 == 0)
    {
        write(1, "0x", 2);
        if(mod->precf > 0 && mod->wdtx && mod->precf > mod->wdtx)
        {
            spec->r = ft_strlen(spec->s) - 3;
            while (spec->r  && spec->r < mod->precf)
            {
                write(1, "0", 1);
                mod->nprinted++;
                spec->r--;
            }
        }
        write(1, spec->s, ft_strlen(spec->s));
        mod->nprinted = ft_strlen(spec->s) + 3;
    }
}

void    check_zero_p(t_pr *mod, t_spec_o *spec)
{
     if(spec->check_0 == 1 && mod->precf <= 0 && !mod->wdtx)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        if (mod->precf != 0)
        {   
            write(1, "0", 1);
            mod->nprinted++;
        }
    }

     if(spec->check_0 == 1 && mod->precf == -1 && mod->wdtx && mod->minus == 1)
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
        write(1, "0", 1);
        mod->nprinted++;
    }
}

void    type_p(t_pr *mod, t_spec_o *spec)
{
    spec->n = (unsigned long)va_arg(*(mod->ap), void*);
    spec->l = spec->n;
    spec->i = 0;
    spec->r = 0;
    spec->check_0 = 0;

    while(spec->n > 0)
    {
        spec->n = spec->n / 16;
        spec->i++;
    } 
    spec->s = ft_strnew(spec->l == 0 ? 1 : spec->i); // если l = 0, то отправляем в стрнью ,если нет, то отправляем i.
    if(spec->l == 0)
    {
        spec->s[0] = '0';
        spec->check_0 = 1;
    }    
    
    while(spec->l > 0)
    {
        if((spec->l % 16) <= 9)
            spec->s[--spec->i] = (spec->l % 16) + '0';
        else
            spec->s[--spec->i] = (spec->l % 16) + 87; 
        spec->l = spec->l / 16;
    }
}

void   print_p(t_pr *mod)
{
    t_spec_o spec;

    type_p(mod, &spec);
    check_zero_p(mod, &spec);
    if(mod->minus == 1)
        if_minus_p(mod, &spec);
    
    while(mod->wdtx > (int)ft_strlen(spec.s) + 2)
    {
        write(1, " ", 1);
        mod->nprinted++;
        mod->wdtx--;
    }
    if(mod->minus == 0)
        if_no_minus_p(mod, &spec);
    check_p(mod, &spec);
    free(spec.s);
}