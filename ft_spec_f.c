/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/03/13 22:38:39 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_whole(long num_start)
{
	int	len_whole;

	len_whole = 1;
	while (num_start / 10 > 0)
	{
		num_start = num_start / 10;
		len_whole++;
	}
	return (len_whole);
}

int		ft_rounding(t_float *fl)
{
	fl->frt[fl->i] = fl->frt[fl->i] + 1;
	if (fl->frt[fl->i] == 10)
	{
		fl->frt[fl->i] = 0;
		fl->i--;
		if (fl->i != -1)
			ft_rounding(fl);
		else
			return (1);
	}
	else
		return (0);
	if (fl->i == -1)
		return (1);
	else
		return (0);
}

void	ft_fill_fl(t_float *fl)
{
	fl->f = 0;
	fl->n_st = 0;
	fl->n_ed = 0;
	fl->frt = 0;
	fl->i = 0;
	fl->k = 0;
	fl->ch_s = 0;
	fl->len_wh = 0;
}

void	print_f(t_pr *mod)
{
	t_float	*fl;

	if (!(fl = malloc(sizeof(t_float))))
		return ;
	ft_fill_fl(fl);
	if (mod->leng == 5)
		fl->f = va_arg(*mod->ap, long double);
	else
		fl->f = va_arg(*mod->ap, double);
	if (ft_float_1(fl->f, mod->precf))
		return ;
	ft_separ_fl(fl, mod);
	ft_fill_frt(fl, mod);
	ft_check_s(fl, mod);
	if (mod->minus == 1)
		ft_print_fl_min(fl, mod);
	ft_print_sp(fl, mod);
	if (mod->minus != 1)
		ft_print_fl(fl, mod);
	free(fl->frt);
	free(fl);
}
