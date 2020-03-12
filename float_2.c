/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:08:47 by soyster           #+#    #+#             */
/*   Updated: 2020/03/05 23:13:42 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_act_wdtx(t_float *fl, t_pr *mod)
{
	int	act_wdtx;

	act_wdtx = ft_len_whole(fl->n_st) +
	(mod->precf != 0 ? +mod->precf : +0) + (mod->precf != 0 ? +1 : +0)
	+ ((fl->ch_s == 1 || mod->plus == 1) ? +1 : +0)
	+ ((mod->hash == 1 && mod->precf == 0) ? +1 : +0)
	+ ((mod->space == 1 && !fl->ch_s) ? +1 : +0);
	return (act_wdtx);
}

void	ft_print_sp(t_float *fl, t_pr *mod)
{
	int	act_wdtx;

	if (mod->space == 1 && !fl->ch_s && mod->plus == 1
	&& mod->minus != 1)
	{
		write(1, " ", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	act_wdtx = ft_act_wdtx(fl, mod);
	if (mod->wdtx)
	{
		fl->len_wh = ft_len_whole(fl->n_st);
		while (--mod->wdtx >= act_wdtx)
		{
			if (mod->zero != 1 || (mod->zero == 1
			&& mod->minus == 1))
				write(1, " ", 1);
			else
				write(1, "0", 1);
			mod->nprinted = mod->nprinted + 1;
		}
	}
}

void	ft_print_fl(t_float *fl, t_pr *mod)
{
	if (fl->ch_s == 1 && mod->zero != 1)
	{
		write(1, "-", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	if (mod->plus == 1 && !fl->ch_s && mod->zero != 1)
	{
		write(1, "+", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	ft_putlongnbr(fl->n_st, mod);
	if (mod->precf != 0 || mod->hash == 1)
	{
		write(1, ".", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	while (fl->k < mod->precf)
		ft_putlongnbr(fl->frt[fl->k++], mod);
}

void	ft_putlongnbr(long n, t_pr *mod)
{
	if (n < 0)
	{
		write(1, "-", 1);
		mod->nprinted++;
		n = n * -1;
	}
	if (n > 9)
		ft_putlongnbr(n / 10, mod);
	ft_putchar(n % 10 + '0');
	mod->nprinted++;
}
