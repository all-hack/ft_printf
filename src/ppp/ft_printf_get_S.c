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

void	ft_printf_get_S(t_mod *conv, va_list args)
{	
	wchar_t *tmp1;
	intmax_t	size;
	intmax_t	i;

	size = conv->prec;
	i = 0;
	if (!(conv->length))	
	{
		tmp1 = va_arg(args, wchar_t*);
		if (size >= 0)
		{
			conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
			while (tmp1[i++] && i < size)
				conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
		}
		else
		{
			conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));	
			while (tmp1[i++])
				conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));	
		}
		// if (*(conv->substring) == '\0')
		// 	ft_printf_fstrinsert(&(conv->substring), "0", 0, 1);
	}		
}