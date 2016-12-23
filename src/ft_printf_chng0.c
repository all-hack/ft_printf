/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strchri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"


void	ft_printf_chng_char(t_mod *conv, signed char num)
{
	if (num < 0)
		conv->substring = ft_printf_itoa_base(-num, 10, 1);	
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_uchar(t_mod *conv, unsigned char num)
{
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_short(t_mod *conv, short num)
{	
	if (num < 0)
		conv->substring = ft_printf_itoa_base(-num, 10, 1);	
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_ushort(t_mod *conv, unsigned short num)
{		
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_int(t_mod *conv, int num)
{	
	intmax_t	nam;

	if (num < 0)
	{
		nam = num;
		conv->substring = ft_printf_itoa_base(-nam, 10, 1);	
	}
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}