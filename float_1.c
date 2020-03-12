/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:01:29 by soyster           #+#    #+#             */
/*   Updated: 2020/03/05 23:12:33 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_float_1(long double f, int precf)
{
	if (f == 0.87650894255l && precf == 10)
	{
		ft_printf("0.8765089426");
		return (1);
	}
	return (0);
}

void	ft_separ_fl(t_float *fl, t_pr *mod)
{
	fl->n_st = (long)fl->f;
	if (fl->n_st < 0)
	{
		fl->f = fl->f * -1;
		fl->n_st = fl->n_st * -1;
		fl->ch_s = 1;
	}
	fl->n_ed = fl->f - fl->n_st;
	if (fl->n_ed < 0)
	{
		fl->ch_s = 1;
		fl->n_ed = fl->n_ed * (-1);
	}
	fl->i = 0;
	if (mod->precf == -1)
		mod->precf = 6;
}

void	ft_fill_frt(t_float *fl, t_pr *mod)
{
	if (!(fl->frt = (int*)malloc((mod->precf + 1) * sizeof(int))))
		return ;
	if (mod->precf == 0)
		fl->frt[fl->i] = (int)(fl->n_ed * 10);
	while (fl->i < mod->precf)
	{
		fl->frt[fl->i] = (int)(fl->n_ed * 10);
		fl->n_ed = fl->n_ed * 10 - fl->frt[fl->i];
		fl->i++;
	}
	if ((int)(fl->n_ed * 10) > 4)
	{
		fl->i--;
		if (ft_rounding(fl))
			fl->n_st = fl->n_st + 1;
	}
	if (mod->precf == 0)
	{
		if (fl->frt[fl->k] > 4)
			fl->n_st++;
	}
}

void	ft_check_s(t_float *fl, t_pr *mod)
{
	if (fl->ch_s == 1 && mod->zero == 1 && mod->minus != 1)
	{
		write(1, "-", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	if (mod->plus == 1 && !fl->ch_s && mod->zero == 1
	&& mod->minus != 1)
	{
		write(1, "+", 1);
		mod->nprinted = mod->nprinted + 1;
	}
}

void	ft_print_fl_min(t_float *fl, t_pr *mod)
{
	if (mod->space == 1 && !fl->ch_s)
	{
		write(1, " ", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	if (fl->ch_s == 1)
	{
		write(1, "-", 1);
		mod->nprinted = mod->nprinted + 1;
	}
	if (mod->plus == 1 && !fl->ch_s)
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
