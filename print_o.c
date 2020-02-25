#include "ft_printf.h" 

void   print_o(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    int i; // количество символов

    // if(mod->leng == 1)
    //     l = (long)(char)va_arg(*(mod->ap), int);
    // else if(mod->leng == 2)
    //     l = (long)(short int)va_arg(*(mod->ap), int);
    // else if(mod->leng == 3 || mod->leng == 4)
    //     l = va_arg(*(mod->ap), long int);
    // else 
    //     l = (long)va_arg(*(mod->ap), int);

    n = (unsigned long)va_arg(*(mod->ap), void*);
    l = n;
    i = 0;


    // printf("%lu\n", n);
    // printf("%lu\n", l);

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
    
    while(mod->wdtx > (int)ft_strlen(s))
    {
        if(mod->hash == 0)
            write(1, " ", 1);
        
        mod->wdtx--;
    }
    if(mod->hash == 1 && mod->minus ==  0)
    {
        write(1, "0", 1);
    }
    write(1, s, (int)ft_strlen(s));


}