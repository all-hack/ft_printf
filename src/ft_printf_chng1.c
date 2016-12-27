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

void	ft_printf_chng_uint(t_mod *conv, unsigned int num)
{		
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_long(t_mod *conv, long num)
{	
	if (num < 0)
		conv->substring = ft_printf_itoa_base(-num, 10, 1);	
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_ulong(t_mod *conv, unsigned long num)
{	
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_size_t(t_mod *conv, size_t num)
{	
	conv->substring = ft_printf_itoa_base(num, 10, 0);
}

void	ft_printf_chng_longlong(t_mod *conv, long long num)
{	
	if (num < 0)
		conv->substring = ft_printf_itoa_base(-num, 10, 1);	
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}