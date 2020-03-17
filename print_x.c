#include "ft_printf.h"

void    print_with_precf_x(t_pr *mod, t_spec_o *spec)
{
    if ((mod->precf > 0 || mod->precf == -1))
    {
        write(1, spec->s, ft_strlen(spec->s));
        mod->nprinted += ft_strlen(spec->s); 
    }
    if (mod->precf == 0 && mod->wdtx != 0 && spec->check_0 == 1)
    {
        write(1, " ", 1);
        mod->nprinted++;
    } 
}
void    if_no_minus_x(t_pr *mod, t_spec_o *spec)
{
     if(mod->minus == 0)
    {
        if(mod->wdtx && mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(spec->s) + ((mod->hash && spec->check_0 == 0) ? 2 : 0))
                spec->r = mod->wdtx - ft_strlen(spec->s) - ((mod->hash && spec->check_0 == 0) ? 2 : 0);
            if(mod->zero == 1 && mod->precf <= 0)
            {
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
                    spec->r--;
                    mod->nprinted++;
                }
                    
                if(mod->hash == 1 && spec->check_0 == 0)
                {
                     write(1, "0x", 2);
                     mod->nprinted += 2;
                }   
            }
        }
        print_with_precf_x(mod, spec);
    }
}

void    if_minus_x(t_pr *mod, t_spec_o *spec)
{
    if(mod->minus == 1)
    {
        if ((mod->precf > 0 || mod->precf == -1)) //&& check_0 == 0)
        {
            write(1, spec->s, ft_strlen(spec->s));
            mod->nprinted += ft_strlen(spec->s);
        }    
         else
        {    
            write(1, " ", 1);
            mod->nprinted++;
        }
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(spec->s) + ((mod->hash && spec->check_0 == 0) ? 2 : 0))
                spec->r = mod->wdtx - ft_strlen(spec->s) - ((mod->hash && spec->check_0 == 0) ? 2 : 0);
            while(spec->r)
            {
                write(1, " ", 1);
                mod->nprinted++;
                spec->r--;
            }
        }
    }
}

void	print_zero_hash_precf_x(t_pr *mod, t_spec_o *spec)
{
    if(mod->zero == 1 && mod->hash == 0 && mod->precf == -1 && mod->wdtx > (int)ft_strlen(spec->s))
         spec->s = ft_strjoin("0", spec->s, 2);

    // точность
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
    // хэш
    if(mod->hash == 1 && spec->check_0 == 0 && 
    ((mod->zero == 1 && mod->precf <= 0) || ((mod->zero == 0 || (mod->zero == 1 && mod->precf > 0)) 
    && (mod->wdtx == mod->precf || mod->wdtx == 0 || mod->minus == 1 
    || (spec->s[0] == '0' && mod->precf >= mod->wdtx)))))
    {
        write(1, "0x", 2);
        mod->nprinted += 2;
    }    
}

void    ft_x_x(t_spec_o *spec)
{
    spec->l = spec->n;
    spec->i = 0;
    spec->r = 0;
    spec->q = 0;
    spec->check_0 = 0; //n    
    while(spec->n > 0)
    {
        spec->n = spec->n / 16;
        spec->i++;
    } 
    spec->s = ft_strnew(spec->l == 0 ? 1 : spec->i); 
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
    while(spec->l > 0)
    {
        spec->s[--spec->i] = (spec->l % 10) + '0';
        spec->l = spec->l / 10;
    } 
}

void    tipe_x(t_pr *mod, t_spec_o *spec)
{
    if(mod->leng == 1)
        spec->n = (unsigned long)( unsigned char)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 2)
        spec->n = (unsigned long)( unsigned short int)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 3 || mod->leng == 4)
        spec->n = va_arg(*(mod->ap), unsigned long int);
    else 
        spec->n = (unsigned long)va_arg(*(mod->ap), unsigned int);
}
void   print_x(t_pr *mod)
{
    t_spec_o spec;
    
    tipe_x(mod, &spec);
    ft_x_x(&spec);
    print_zero_hash_precf_x(mod, &spec);
    if_minus_x(mod, &spec);
    if_no_minus_x(mod, &spec);
    free(spec.s);
}