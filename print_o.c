/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:06:21 by lniki             #+#    #+#             */
/*   Updated: 2020/03/17 14:35:31 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_no_minus(t_pr *mod, t_spec_o *spec)
{
	if (mod->wdtx && mod->wdtx > mod->precf)
	{
		if (mod->wdtx > (int)ft_strlen(spec->s))
			spec->r = mod->wdtx - (int)ft_strlen(spec->s);
		if (mod->zero == 1 && mod->precf <= 0)
		{
			while (spec->r)
			{
				write(1, "0", 1);
				spec->r--;
				mod->nprinted++;
			}
		}
		else
		{
			while (spec->r)
			{
				write(1, " ", 1);
				spec->r--;
				mod->nprinted++;
			}
		}
	}
	write(1, spec->s, ft_strlen(spec->s));
	mod->nprinted += (int)ft_strlen(spec->s);
}

void	if_minus(t_pr *mod, t_spec_o *spec)
{
	write(1, spec->s, ft_strlen(spec->s));
	mod->nprinted += (int)ft_strlen(spec->s);
	if (mod->wdtx > mod->precf)
	{
		if (mod->wdtx > (int)ft_strlen(spec->s))
			spec->r = mod->wdtx - (int)ft_strlen(spec->s);
		while (spec->r)
		{
			write(1, " ", 1);
			spec->r--;
			mod->nprinted++;
		}
	}
}

void	print_zero_hash_precf(t_pr *mod, t_spec_o *spec)
{
	if (spec->l == 0 && mod->precf != 0)
		spec->s = ft_strjoin("0", spec->s, 2);
	while (spec->l > 0)
	{
		spec->s[--spec->i] = (spec->l % 8) + '0';
		spec->l = spec->l / 8;
	}
	if (mod->hash == 1 && spec->s[0] != '0')
		spec->s = ft_strjoin("0", spec->s, 2);
	if (mod->precf != -1)
	{
		if (mod->precf > (int)ft_strlen(spec->s))
			spec->r = mod->precf - (int)ft_strlen(spec->s);
		while (spec->r)
		{
			spec->s = ft_strjoin("0", spec->s, 2);
			spec->r--;
		}
	}
}

void	type(t_pr *mod, t_spec_o *spec)
{
	if (mod->leng == 1)
		spec->n = (unsigned long)(unsigned char)va_arg(*(mod->ap), unsigned int);
	else if (mod->leng == 2)
		spec->n = (unsigned long)(unsigned short int)va_arg(*(mod->ap), unsigned int);
	else if (mod->leng == 3 || mod->leng == 4)
		spec->n = va_arg(*(mod->ap), unsigned long int);
	else
		spec->n = (unsigned long)va_arg(*(mod->ap), unsigned int);
	spec->l = spec->n;
	spec->i = 0;
	spec->r = 0;
	while (spec->n > 0)
	{
		spec->n = spec->n / 8;
		spec->i++;
	}
	spec->s = ft_strnew(spec->l == 0 ? 1 : spec->i);
}

void	print_o(t_pr *mod)
{
	t_spec_o spec;

	type(mod, &spec);
	print_zero_hash_precf(mod, &spec);
	if (mod->minus == 1)
		if_minus(mod, &spec);
	if (mod->minus == 0)
		if_no_minus(mod, &spec);
	free(spec.s);
	spec.s = NULL;
}
