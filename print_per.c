/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:40:58 by lniki             #+#    #+#             */
/*   Updated: 2020/03/15 20:35:07 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_per(t_pr *mod)
{
    mod->nprinted += mod->wdtx == 0 ? 1 : mod->wdtx; // если ширина нулевая, то nprinted = 1, если нет то равен ширине
    if(mod->minus == 1)
        write(1, "%", 1);
    while(mod->wdtx > 1)
    {
        if(mod->minus == 0 && mod->zero == 1)
            write(1, "0", 1);
        else
            write(1, " ", 1);
        mod->wdtx--;
    }
    if(mod->minus == 0) 
        write(1, "%", 1);
}