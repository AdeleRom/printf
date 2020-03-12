/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:51:10 by lniki             #+#    #+#             */
/*   Updated: 2020/03/06 16:37:46 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "lib/libft.h"

 typedef  struct s_pr
    {
        char    *format;
        va_list *ap;

        int     nprinted; // количество выведенных символов

        int     i; // индекс строки формата
        int     len; // длина каждого аргумента

        int    minus; // -
        int    plus; // +
        int    space; // ' '
        int     zero; // 0
        int    hash; // #
           
        int     wdtx; //переменная для ширины
        // int     prec; // .#
        int     precf; // .
        int     leng; // hh h l ll L 
        
        char    spec; //переменная для спецификатора
                
    } t_pr;

typedef struct	s_float
    {
        long double	f;
        long		n_st;
        long double	n_ed;
        int			*frt;
        int			i;
        int			k;
        int			ch_s;
        int			len_wh;
    }				t_float;
    
    int     sign(char *s, char *q);
    int     ft_printf(const char *format, ...);
    void    print_c(t_pr *mod);
    void    print_s(t_pr *mod);
    void   print_per(t_pr *mod);
    void   print_p(t_pr *mod);
    void   print_d(t_pr *mod);
    void   print_o(t_pr *mod);
    void   print_u(t_pr *mod);
    void   print_x(t_pr *mod);

    int		ft_act_wdtx(t_float *fl, t_pr *mod);
    void	ft_print_sp(t_float *fl, t_pr *mod);
    void	ft_print_fl(t_float *fl, t_pr *mod);
    void	ft_putlongnbr(long n, t_pr *mod);
    int		ft_float_1(long double f, int precf);
    void	ft_separ_fl(t_float *fl, t_pr *mod);
    void	ft_fill_frt(t_float *fl, t_pr *mod);
    void	ft_check_s(t_float *fl, t_pr *mod);
    void	ft_print_fl_min(t_float *fl, t_pr *mod);
    void	print_f(t_pr *mod);
    void	ft_fill_fl(t_float *fl);
    int		ft_rounding(t_float *fl);
    int		ft_len_whole(long num_start);

#endif