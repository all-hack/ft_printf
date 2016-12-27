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

#include "libftprintf.h"

void	ft_printf_chng_ulonglong(t_mod *conv, unsigned long long num)
{	
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_intmax_t(t_mod *conv, intmax_t num)
{	
	if (num < 0)
		conv->substring = ft_printf_itoa_base(-num, 10, 1);	
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_uintmax_t(t_mod *conv, uintmax_t num)
{		
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

char	*ft_printf_chng_wchar_t(t_mod *conv, wchar_t chr, char *str)
{		
	if (chr < 0200)
	{
		str = ft_printf_strnew(1);	
		str[0] = (char)chr;
	}
	else if (chr >= 0200 && chr <= 03777)
	{	
		str = ft_printf_strnew(2);		
		str[0] = (char)(((chr  >> 6 | 0340) ^ 0340) | 0300);
		str[1] = (char)(((chr | 0300) ^ 0300) | 0200);
	}
	else if (chr >= 04000 && chr <= 0177777)
	{				 				 
		str = ft_printf_strnew(3);		
		str[0] = (char)(((chr >> 12 | 0360) ^ 0360) | 0340);
		str[1] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
		str[2] = (char)(((chr | 0300) ^ 0300) | 0200);
	}
	else if (chr >= 0200000 && chr <= 04177777)
	{
		str = ft_printf_strnew(4);
		str[0] = (char)(((chr >> 18 | 0370) ^ 0370) | 0360);
		str[1] = (char)(((chr >> 12 | 0300) ^ 0300) | 0200);
		str[2] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
		str[3] = (char)(((chr | 0300) ^ 0300) | 0200);		
	}
	// else if (chr > 04177777)
	else
	{
		chr = 0177775;
		str = ft_printf_strnew(3);		
		str[0] = (char)(((chr >> 12 | 0360) ^ 0360) | 0340);
		str[1] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
		str[2] = (char)(((chr | 0300) ^ 0300) | 0200);
	}
	return (str);
}