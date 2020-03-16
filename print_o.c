#include "ft_printf.h" 

void   print_o(t_pr *mod)
{
    unsigned long  n; // изначальное число
    unsigned long l; // тоже самое, чтоб запомнить
    char *s; // строка для того чтоб туда записать конечный вид
    int i; // количество символов
    int r; // количество нолей или пробелов (ширина - длина строки)


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
  
    while(n > 0)
    {
        n = n / 8;
        i++;
    }

    s = ft_strnew(l == 0 ? 1 : i); 
   
    //для нуля
    if (l == 0 && mod->precf != 0)
        s = ft_strjoin("0", s);

    while(l > 0)
    {
        s[--i] = (l % 8) + '0';
        l = l / 8;
    } 
    
    // хэш
    if(mod->hash == 1 && s[0] != '0')
        s = ft_strjoin("0", s);

    // точность
    if(mod->precf != -1)
    {
        if (mod->precf > (int)ft_strlen(s))
            r = mod->precf - ft_strlen(s);
        while(r)
         {
             s = ft_strjoin("0", s);
             r--;
         }   
    }
    // есть минус
    if(mod->minus == 1)
    {
        write(1, s, ft_strlen(s));
        mod->nprinted += ft_strlen(s);
        if(mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(s))
                r = mod->wdtx - ft_strlen(s);
            while(r)
            {
                write(1, " ", 1);
                r--;
                mod->nprinted++;
            }
        }
    }
    // нет минуса
    if(mod->minus == 0)
    {
        if(mod->wdtx && mod->wdtx > mod->precf)
        {
            if (mod->wdtx > (int)ft_strlen(s))
                r = mod->wdtx - ft_strlen(s);
            if(mod->zero == 1 && mod->precf <= 0)
            {
                while(r)
                {
                    write(1, "0", 1);
                    r--;
                    mod->nprinted++;
                }    
            }   
            else 
            {
                while(r)
                {
                    write(1, " ", 1);
                    r--;
                    mod->nprinted++;
                } 
            }
        }
        write(1, s, ft_strlen(s));
        mod->nprinted += ft_strlen(s);
    }
    free(s);
}