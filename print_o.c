#include "ft_printf.h" 

void   print_o(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    int i; // количество символов

    if(mod->leng == 1)
        n = (unsigned long)( unsigned char)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 2)
        n = (unsigned long)( unsigned short int)va_arg(*(mod->ap), unsigned int);
    else if(mod->leng == 3 || mod->leng == 4)
        n = va_arg(*(mod->ap), unsigned long int);
    else 
        n = (unsigned long)va_arg(*(mod->ap), unsigned int);

    //n = (unsigned long)va_arg(*(mod->ap), void*);
    l = n;
    i = 0;

    while(n > 0)
    {
        n = n / 8;
        i++;
    }

    s = ft_strnew(l == 0 ? 1 : i); 

    while(l > 0)
    {
        s[--i] = (l % 8) + '0';
        l = l / 8;
    } 
    if(mod->hash == 1)
        s = ft_strjoin("0", s);
    
    if(mod->minus == 1 && mod->zero == 0 && mod->)
    {
        write(1, s, (int)ft_strlen(s));
        while(mod->wdtx > (int)ft_strlen(s))
        {
            write(1, " ", 1);
            mod->wdtx--;
        }
    }
    if(mod->minus == 0)
    {
        while(mod->wdtx > (int)ft_strlen(s))
        {
            write(1, " ", 1);
            mod->wdtx--;
        }
    
    write(1, s, (int)ft_strlen(s));
    }
    


}