/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:17:49 by soyster           #+#    #+#             */
/*   Updated: 2020/03/05 23:14:43 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// void	ft_spec_r(va_list all_arg, t_flag *all_mod)
// {
// 	t_np	np;

// 	np.src = va_arg(all_arg, char *);
// 	np.i = 0;
// 	if (np.src == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		all_mod->res = all_mod->res + 6;
// 		return ;
// 	}
// 	ft_np_1(&np, all_mod);
// }

// void	ft_np_1(t_np *np, t_flag *all_mod)
// {
// 	while (np->src[np->i])
// 	{
// 		np->src[np->i] == 0 ? ft_putstr_res("[NUL]", 5, all_mod) : 0;
// 		np->src[np->i] == 1 ? ft_putstr_res("[SOH]", 5, all_mod) : 0;
// 		np->src[np->i] == 2 ? ft_putstr_res("[STX]", 5, all_mod) : 0;
// 		np->src[np->i] == 3 ? ft_putstr_res("[ETX]", 5, all_mod) : 0;
// 		np->src[np->i] == 4 ? ft_putstr_res("[EOT]", 5, all_mod) : 0;
// 		np->src[np->i] == 5 ? ft_putstr_res("[ENQ]", 5, all_mod) : 0;
// 		np->src[np->i] == 6 ? ft_putstr_res("[ACK]", 5, all_mod) : 0;
// 		np->src[np->i] == 7 ? ft_putstr_res("[BEL]", 5, all_mod) : 0;
// 		np->src[np->i] == 8 ? ft_putstr_res("[BS]", 4, all_mod) : 0;
// 		np->src[np->i] == 9 ? ft_putstr_res("[TAB]", 5, all_mod) : 0;
// 		np->src[np->i] == 10 ? ft_putstr_res("[LF]", 4, all_mod) : 0;
// 		np->src[np->i] == 11 ? ft_putstr_res("[VT]", 4, all_mod) : 0;
// 		np->src[np->i] == 12 ? ft_putstr_res("[FF]", 4, all_mod) : 0;
// 		np->src[np->i] == 13 ? ft_putstr_res("[CR]", 4, all_mod) : 0;
// 		np->src[np->i] == 14 ? ft_putstr_res("[SO]", 4, all_mod) : 0;
// 		np->src[np->i] == 15 ? ft_putstr_res("[SI]", 4, all_mod) : 0;
// 		np->src[np->i] == 16 ? ft_putstr_res("[DLE]", 5, all_mod) : 0;
// 		ft_np_2(np, all_mod);
// 	}
// }

// void	ft_np_2(t_np *np, t_flag *all_mod)
// {
// 	np->src[np->i] == 17 ? ft_putstr_res("[DC1]", 5, all_mod) : 0;
// 	np->src[np->i] == 18 ? ft_putstr_res("[DC2]", 5, all_mod) : 0;
// 	np->src[np->i] == 19 ? ft_putstr_res("[DC3]", 5, all_mod) : 0;
// 	np->src[np->i] == 20 ? ft_putstr_res("[DC4]", 5, all_mod) : 0;
// 	np->src[np->i] == 21 ? ft_putstr_res("[NAK]", 5, all_mod) : 0;
// 	np->src[np->i] == 22 ? ft_putstr_res("[SYN]", 5, all_mod) : 0;
// 	np->src[np->i] == 23 ? ft_putstr_res("[ETB]", 5, all_mod) : 0;
// 	np->src[np->i] == 24 ? ft_putstr_res("[CAN]", 5, all_mod) : 0;
// 	np->src[np->i] == 25 ? ft_putstr_res("[EM]", 4, all_mod) : 0;
// 	np->src[np->i] == 26 ? ft_putstr_res("[SUB]", 5, all_mod) : 0;
// 	np->src[np->i] == 27 ? ft_putstr_res("[ESC]", 5, all_mod) : 0;
// 	np->src[np->i] == 28 ? ft_putstr_res("[FS]", 4, all_mod) : 0;
// 	np->src[np->i] == 29 ? ft_putstr_res("[GS]", 4, all_mod) : 0;
// 	np->src[np->i] == 30 ? ft_putstr_res("[RS]", 4, all_mod) : 0;
// 	np->src[np->i] == 31 ? ft_putstr_res("[US]", 4, all_mod) : 0;
// 	np->i++;
// }

// void	ft_putstr_res(char *src, int res, t_flag *all_mod)
// {
// 	ft_putstr((const char*)src);
// 	all_mod->res = all_mod->res + res;
// }
