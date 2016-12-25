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

void	ft_printf_get_percent(t_mod *conv, va_list args)
{	
	conv->substring = ft_printf_strdup("%");		
}

void	ft_printf_get_X(t_mod *conv, va_list args)
{		
	if (!(conv->length))
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);	
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, uintmax_t), 16, 0);
	else if (ft_printf_strcmp(conv->length, "l") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long), 16, 0);
	else if (ft_printf_strcmp(conv->length, "z") == 0)	
		conv->substring = ft_printf_itoa_base(va_arg(args, size_t), 16, 0);		
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);
	else if (ft_printf_strcmp(conv->length, "ll") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long long), 16, 0);		
	ft_printf_strupper(conv->substring);
}

void	ft_printf_get_D(t_mod *conv, va_list args)
{		
	if (!(conv->length))	
		ft_printf_chng_long(conv, va_arg(args, long));	
}

void	ft_printf_get_U(t_mod *conv, va_list args)
{		
	if (!(conv->length))
		ft_printf_chng_ulong(conv, va_arg(args, unsigned long));	
}

void	ft_printf_get_O(t_mod *conv, va_list args)
{		
	if (!(conv->length))		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long), 8, 0);
}

