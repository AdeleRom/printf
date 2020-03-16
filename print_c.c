/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:57:06 by lniki             #+#    #+#             */
/*   Updated: 2020/03/15 22:31:28 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   print_c(t_pr *mod)
{
    int c;

	c = va_arg(*(mod->ap), int);
    mod->nprinted += mod->wdtx == 0 ? 1 : mod->wdtx; // если ширина нулевая, то nprinted = 1, если нет то равен ширине
    if(mod->minus == 1)
        write(1, &c, 1);
    while(mod->wdtx > 1)
    {
        write(1, " ", 1);
        mod->wdtx--;
    }
    if(mod->minus == 0)
        write(1, &c, 1);
}