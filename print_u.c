#include "ft_printf.h" 

void    if_no_minus_u(t_pr *mod, t_spec_o *spec)
{
    if(mod->wdtx && mod->wdtx > mod->precf)
    {
        if (mod->wdtx > (int)ft_strlen(spec->s))
            spec->r = mod->wdtx - ft_strlen(spec->s);
        if(mod->zero == 1 && mod->precf <= 0)
        {
            while(spec->r)
            {
                write(1, "0", 1);
                mod->nprinted++;
                spec->r--;
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
        }
    }
    write(1, spec->s, ft_strlen(spec->s));
    mod->nprinted += ft_strlen(spec->s);
}

void    if_minus_u(t_pr *mod, t_spec_o *spec)
{
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
void    check_zero_precf_u(t_pr *mod, t_spec_o *spec)
{
    if (spec->l == 0 && mod->precf != 0)
        spec->s = ft_strjoin("0", spec->s, 2);

    while(spec->l > 0)
    {
        spec->s[--spec->i] = (spec->l % 10) + '0';
        spec->l = spec->l / 10;
    } 
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
}

void    type_u(t_pr *mod, t_spec_o *spec)
{
    if(mod->leng == 1)
        spec->n = (unsigned long)( unsigned char)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 2)
        spec->n = (unsigned long)( unsigned short int)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 3 || mod->leng == 4)
        spec->n = va_arg(*(mod->ap), unsigned long int);
    else 
        spec->n = (unsigned long)va_arg(*(mod->ap), unsigned int);

    spec->l = spec->n;
    spec->i = 0;
    spec->r = 0;
  
    while(spec->n > 0)
    {
        spec->n = spec->n / 10;
        spec->i++;
    }

    spec->s = ft_strnew(spec->l == 0 ? 1 : spec->i); 
}

void   print_u(t_pr *mod)
{

    t_spec_o spec; 

    type_u(mod, &spec);
    check_zero_precf_u(mod, &spec);
    if(mod->minus == 1)
        if_minus_u(mod, &spec);
    if(mod->minus == 0)
        if_no_minus_u(mod, &spec);
    free(spec.s);
}