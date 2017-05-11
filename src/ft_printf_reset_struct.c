/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:09 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:11 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_reset_struct(t_mod **this)
{
	if (this && *this)
	{
		// printf("reset struct: 1\n");
		if ((*this)->flag)
			ft_printf_dfree_hack(&((*this)->flag));
		// printf("reset struct: 2\n");
		if ((*this)->prepend)
			ft_printf_dfree_hack(&((*this)->prepend));
		// printf("reset struct: 3\n");
		if ((*this)->length)
			ft_printf_dfree_hack(&((*this)->length));
		// printf("reset struct: 4\n");
		if ((*this)->conversion)
			ft_printf_dfree_hack(&((*this)->conversion));
		// printf("reset struct: 5\n");
		if ((*this)->substring)
		{
			// ft_printf_dfree_hack(&((*this)->substring));
			ft_printf_strdel(&((*this)->substring));
		}
			
		// printf("reset struct: 6\n");
		if ((*this)->mfieldwidth)
			ft_printf_dfree_hack(&((*this)->mfieldwidth));
		// printf("reset struct: 7\n");
		if ((*this)->precision)
			ft_printf_dfree_hack(&((*this)->precision));
		// printf("reset struct: 8\n");
		(*this)->mfw = -1;
		(*this)->prec = -1;
		(*this)->cmfw = ' ';
		(*this)->cprec = '\0';
		(*this)->srt_seq = 0;
		(*this)->end_seq = 0;
	}
}
